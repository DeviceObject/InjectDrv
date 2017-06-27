#include "DrvCfg.h"
#include "x86Call.h"
#include "x64Call.h"

extern void x64_Call_Loader(EXALLOCATEPOOLWITHTAG MyExAllocatePoolWithTag,PUCHAR pBaseAddr);
extern void x64_Call_Work();
//PCHAR pShow = "ntoskrnl.exe";
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject,PUNICODE_STRING pUniRegister)
{
	NTSTATUS Status;

	UNREFERENCED_PARAMETER(pDriverObject);
	UNREFERENCED_PARAMETER(pUniRegister);
#ifndef _WIN64
	x86_Call_Initialize(NULL,NULL);
	x86_Call_Work();
#else
	//x64_Call_Loader(NULL,NULL);
	//x64_Call_Work();
	//x64GetNtoskrnlBase();
	
	//DbgPrint(pShow);
	//InitializeFunctionDat(g_pFunctionDat);
	
	Get_Kernel_Api_From_HashValue((PVOID)GetModuleBaseAddress(NULL));
	
#endif
	Status = STATUS_SUCCESS;
	return Status;
}