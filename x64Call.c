#include "DrvCfg.h"
#include "Utils.h"
#include "x64Call.h"

//BOOLEAN MyIsAddressValid(PVOID VirtualAddress)
//{
//	if (((ULONG_PTR)((ULONG)((VirtualAddress & 0xFFFFFFFFFFFFF000) >> 0x24) & 0xFF8) + 0xFFFFF6FB7DBED000) & 1 == 0)
//	{
//		return FALSE;
//	}
//	if (((ULONG_PTR)(((ULONG)(VirtualAddress >> 0x1B)) & 0x1FFFF8) + 0xFFFFF6FB7DA00000) & 1 == 0)
//	{
//		return FALSE;
//	}
//	if ((*(char*)((((ULONG)(VirtualAddress >> 0x12)) & 0x3FFFFFF8) + 0xFFFFF6FB40000000)) & 1 == 0)
//	{
//		return FALSE;
//	}
//}
#ifdef _WIN64

PVOID x64GetNtoskrnlBase()
{
	ULONG_PTR *ulStartSearchAddress;
	PIMAGE_DOS_HEADER pDosHeader;
	PIMAGE_NT_HEADERS pNtHeader;
	PIMAGE_EXPORT_DIRECTORY pEat;

	ulStartSearchAddress = (ULONG_PTR *)0xFFFFF80000000000;
	do 
	{
		if (x64_Check_Address((PVOID)ulStartSearchAddress) != 0)
		{
			pDosHeader = (PIMAGE_DOS_HEADER)ulStartSearchAddress;
			if (pDosHeader->e_magic == IMAGE_DOS_SIGNATURE)
			{
				pNtHeader = (PIMAGE_NT_HEADERS)((ULONG_PTR)pDosHeader + pDosHeader->e_lfanew);
				if (pNtHeader->Signature == IMAGE_NT_SIGNATURE)
				{
					if (pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress != 0 && \
						pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size != 0)
					{
						pEat = (PIMAGE_EXPORT_DIRECTORY)((ULONG_PTR)pDosHeader + pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
						if (pEat->NumberOfFunctions > 0x320)
						{
							return (PVOID)ulStartSearchAddress;
						}
					}
				}
			}
		}
		ulStartSearchAddress += 0x1000;
	} while ((ULONG_PTR)ulStartSearchAddress < 0xFFFFF90000000000);
	return NULL;
}

#endif