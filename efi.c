#include "efi.h"


EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	(void)ImageHandle;			// Otherwise you get a compiler warning, and nobody likes those.
	
	
	// TEXT ATTR: FG = GREEN, BG = RED
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_GREEN, EFI_BLACK));
	
	// CLEAR SCREEN TO BG
	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
	
	// HELLO THE WORLD
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"HELLO WORLD OF EFI HAHAHA!\n");
	
	// TEXT ATTR: FG = YELLOW, BG = BLACK
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_YELLOW, EFI_BLACK));
	
	// PRINT THE MESSAGE
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"Press the 'ANY' key to shutdown\n");
	
	// TEXT ATTR: FG = RED, BG = BLACK
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_RED, EFI_BLACK));
	
	// PRINT THE COOLER MESSAGE
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"yes. the 'ANY' key. you heard me.\n");
	
	// TEXT ATTR: FG = CYAN, BG = BLACK
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_CYAN, EFI_BLACK));
	
	// WAIT FOR KEYPRESS
	EFI_INPUT_KEY key;
	
	while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &key) != EFI_SUCCESS);
	
	// SHUTDOWN
	SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
	
	// NEVER REACHED BUT NEEDED
	return EFI_SUCCESS;
}
