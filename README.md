# ExampleEFI Application

This repository contains an EFI (Extensible Firmware Interface) application written in C.

## Prerequisites

Before running this application, ensure you have the following tools and dependencies installed:

- `clang` compiler for compiling EFI executables.
- `mkfs.vfat` utility for creating a file system on boot image.
- `qemu-system` for running the application.
- `make` for building and running the application

## Installing prerequisites

Install all the packages needed:
```bash
sudo apt install make clang dosfstools qemu-system
```

## Building

To build the EFI application:

1. **Clone Repository:**
```bash
git clone https://github.com/Xaristrike/ExampleEFI
```
```bash
cd ExampleEfi
```
2. **Compile the Application:**
```bash
make
```

## Running with QEMU
To run the EFI application using QEMU:
```bash
make qemu
```

## Running in Text Mode with QEMU
To run the EFI application in text mode, where QEMU outputs to the terminal:
```bash
qemu nographic
```

## Cleaning Up
To clean up build files and other temporary files:
```bash
make clean
```