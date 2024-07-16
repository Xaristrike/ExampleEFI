.POSIX:

CC		= clang
CFLAGS		= -target x86_64-unknown-windows -fuse-ld=lld-link -Wl,-subsystem:efi_application -Wl,-entry:efi_main -std=c17
CWARNFLAGS	= -Wall -Wextra -Wpedantic
CEXTRAFLAGS	= -ffreestanding -nostdlib -mno-red-zone

SRC		= efi.c
TARGET		= BOOTX64.EFI
IMG		= boot.img
MKFS		= mkfs.vfat

DEVELDIR	= $(shell pwd)
MOUNTDIR	= mymnt
BOOTDIR		= mymnt/efi/boot
EFIDIR		= efi

QEMU		= qemu-system-x86_64
QEMUNOG		= qemu-system-x86_64 -nographic
QEMUDSK		= -drive file=/usr/share/ovmf/OVMF.fd,format=raw,if=pflash
QEMUFLAGS	= -cdrom $(IMG)


.PHONY: default
default: all

.PHONY: all
all: clean dirs $(TARGET)


.PHONY: $(TARGET)
$(TARGET): $(SRC) dirs
	@echo "Creating BOOTX64.EFI..."
	@$(CC) $(CFLAGS) $(CWARNFLAGS) $(CEXTRAFLAGS) -o $(EFIDIR)/$@ $<
	@dd if=/dev/zero of=$(IMG) bs=1M count=512 >/dev/null 2>&1
	@sudo $(MKFS) $(IMG) > /dev/null 2>&1
	@sudo mount $(IMG) $(DEVELDIR)/$(MOUNTDIR)/
	@sudo mkdir -p $(BOOTDIR)/
	@sudo cp $(EFIDIR)/$(TARGET) $(BOOTDIR)/bootx64.efi
	@sudo umount $(MOUNTDIR)/


.PHONY: dirs
dirs:
	@echo "Creating necessary directories..."
	@mkdir -p $(MOUNTDIR)
	@mkdir -p $(EFIDIR)


.PHONY: qemu
qemu: $(TARGET)
	@echo "Booting with QEMU..."
	@sudo $(QEMU) $(QEMUDSK) $(QEMUFLAGS)
	@echo "Goodbye."


.PHONY: qemunographic
qemunographic: $(TARGET)
	@echo "Booting with QEMU (terminal)..."
	@sudo $(QEMUNOG) $(QEMUDSK) $(QEMUFLAGS)
	@echo "Goodbye."


.PHONY: clean
clean:
	@if mountpoint -q $(MOUNTDIR); then echo "Unmounting OS directory..."; sudo umount $(DEVELDIR)/$(MOUNTDIR)/; fi
	@echo "Removing build directories..."
	@rm -rf $(MOUNTDIR)
	@rm -rf $(TARGET)
	@rm -rf $(IMG)
	@rm -rf $(EFIDIR)