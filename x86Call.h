#ifndef __X86_CALL_H__
#define __X86_CALL_H__

void InitializeFunctionDat(PFUNCTION_DAT pFunctionDat);
void x86_Call_Initialize(EXALLOCATEPOOLWITHTAG MyExAllocatePoolWithTag,PUCHAR pBaseAddr);
void x86_Call_Work();
ULONG Initialize_Reload(EXALLOCATEPOOLWITHTAG MyExAllocatePoolWithTag,PUCHAR pBaseAddr);
void Sti();
void Cli();
ULONG_PTR ReadCr4();
ULONG_PTR *x86GetNtoskrnlBase();
BOOLEAN SubEntry(PVOID pNtoskrnlBase,EXALLOCATEPOOLWITHTAG MyExAllocatePoolWithTag);
PVOID GetModuleBaseAddress(PCHAR pModuleName);
ULONG_PTR Get_Kernel_Api_From_HashValue(PVOID pImageBase);
PVOID AllocateMemoryFromTargetProcess(PVOID pEProcess);
BOOLEAN InjectProcess(HANDLE hProcessId);
BOOLEAN InsertApc(PVOID pShellCode,PKAPC pApc);
VOID InjectNotifyRoutine(PUNICODE_STRING FullImageName,HANDLE ProcessId,PIMAGE_INFO ImageInfo);

#endif