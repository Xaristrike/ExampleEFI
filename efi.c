#include "efi.h"


EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	(void)ImageHandle;			// Otherwise you get a compiler warning, and nobody likes those.
	
	
	// TEXT ATTRIB: FG = YELLOW, BG = RED
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_GREEN, EFI_BLACK));
	
	// CLEAR SCREEN TO BG
	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
	
	// HELLO THE WORLD
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"HELLO WORLD OF EFI HAHAHA!");
	
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"\n");
	
	// TEXT ATTRIB: FG = RED, BG = BLACK
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_YELLOW, EFI_BLACK));
	
	// PRINT THE MESSAGE
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"Press the 'ANY' key to shutdown");
	
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_RED, EFI_BLACK));
	
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"\n");
	
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"yes. the 'ANY' key. you heard me.");
	
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"\n");
	
	// WAIT FOR KEYPRESS
	EFI_INPUT_KEY key;
	
	while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &key) != EFI_SUCCESS);
	
	// SHUTDOWN
	SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
	
	// NEVER REACHED
	return EFI_SUCCESS;
}
