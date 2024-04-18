#include "efi.h"


EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	(void)ImageHandle;			// Otherwise you get a compiler warning
	
	
	// TEXT ATTRIB: FG = YELLOW, BG = RED
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_YELLOW, EFI_BLACK));
	
	// CLEAR SCREEN TO BG
	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
	
	// HELLO THE WORLD
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"HELLO WORLD OF EFI HAHAHA!\n\n");
	
	// TEXT ATTRIB: FG = RED, BG = BLACK
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_WHITE, EFI_RED));
	
	// PRINT THE MESSAGE
	SystemTable->ConOut->OutputString(SystemTable->ConOut, u"Press the 'ANY' key to shutdown\n\n\n\nyes. the 'ANY' key. you heard me.");
	
	// WAIT FOR KEYPRESS
	EFI_INPUT_KEY key;
	
	while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &key) != EFI_SUCCESS);
	
	// SHUTDOWN
	SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
	
	// NEVER REACHED
	return EFI_SUCCESS;
}
