#ifndef __X64_CALL_H__
#define __X64_CALL_H__

PVOID x64GetNtoskrnlBase();
#ifdef _WIN64
extern ULONG x64_Check_Address(PVOID VirtualAddress);
#endif
#endif