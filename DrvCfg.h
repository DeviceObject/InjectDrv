#ifndef __DRV_CFG_H__
#define __DRV_CFG_H__

#include <ntifs.h>
#include <ntddk.h>
#include "KernelApi.h"
#include <ntdef.h>
#include <ntimage.h>

#define MAX_THREAD_COUNT 64

#define MAKEWORD(a, b)      ((USHORT)(((BYTE)(((ULONG_PTR)(a)) & 0xff)) | ((USHORT)((BYTE)(((ULONG_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((USHORT)(((ULONG_PTR)(a)) & 0xffff)) | ((ULONG)((USHORT)(((ULONG_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((USHORT)(((ULONG_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((USHORT)((((ULONG_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((ULONG_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((ULONG_PTR)(w)) >> 8) & 0xff))

#pragma pack(1)
typedef struct _IMAGE_RELOC
{
	USHORT Offset:12;
	USHORT Type:4;
}IMAGE_RELOC,*PIMAGE_RELOC;
typedef struct _FUNCTION_DAT
{
	PSSETLOADIMAGENOTIFYROUTINE My_PsSetLoadImageNotifyRoutine;
	ULONG My_PsSetLoadImageNotifyRoutine_HashValue;

	//ULONG_PTR My_ZwCreateFile;
	//ULONG My_ZwCreateFile_HashValue;

	//ULONG_PTR My_ZwWriteFile;
	//ULONG My_ZwWriteFile_HashValue;
	PSSETCREATEPROCESSNOTIFYROUTINE My_PsSetCreateProcessNotifyRoutine;
	ULONG My_PsSetCreateProcessNotifyRoutine_HashValue;

	ZWCLOSE My_ZwClose;
	ULONG My_ZwClose_HashValue;

	ZWQUERYSYSTEMINFORMATION My_ZwQuerySystemInformation;
	ULONG My_ZwQuerySystemInformation_HashValue;

	EXALLOCATEPOOLWITHTAG My_ExAllocatePoolWithTag;
	ULONG My_ExAllocatePoolWithTag_HashValue;

	EXFREEPOOLWITHTAG My_ExFreePoolWithTag;
	ULONG My_ExFreePoolWithTag_HashValue;

	OBREFERENCEOBJECTBYHANDLE My_ObReferenceObjectByHandle;
	ULONG My_ObReferenceObjectByHandle_HashValue;

	OBDEREFERENCEOBJECT My_ObDereferenceObject;
	ULONG My_ObDereferenceObject_HashValue;

	PSCREATESYSTEMTHREAD My_PsCreateSystemThread;
	ULONG My_PsCreateSystemThread_HashValue;

	KEWAITFORSINGLEOBJECT My_KeWaitForSingleObject;
	ULONG My_KeWaitForSingleObject_HashValue;

	PSTERMINATESYSTEMTHREAD My_PsTerminateSystemThread;
	ULONG My_PsTerminateSystemThread_HashValue;

	MMCREATEMDL My_MmCreateMdl;
	ULONG My_MmCreateMdl_HashValue;

	MMBUILDMDLFORNONPAGEDPOOL My_MmBuildMdlForNonPagedPool;
	ULONG My_MmBuildMdlForNonPagedPool_HashValue;

	MMMAPLOCKEDPAGES My_MmMapLockedPages;
	ULONG My_MmMapLockedPages_HashValue;

	MMUNMAPLOCKEDPAGES My_MmUnmapLockedPages;
	ULONG My_MmUnmapLockedPages_HashValue;

	PSGETCURRENTPROCESS My_PsGetCurrentProcess;
	ULONG My_PsGetCurrentProcess_HashValue;

	IOGETCURRENTPROCESS My_IoGetCurrentProcess;
	ULONG My_IoGetCurrentProcess_HashValue;

	KESTACKATTACHPROCESS My_KeStackAttachProcess;
	ULONG My_KeStackAttachProcess_HashValue;

	ZWALLOCATEVIRTUALMEMORY My_ZwAllocateVirtualMemory;
	ULONG My_ZwAllocateVirtualMemory_HashValue;

	KEUNSTACKDETACHPROCESS My_KeUnstackDetachProcess;
	ULONG My_KeUnstackDetachProcess_HashValue;

	PSLOOKUPPROCESSBYPROCESSID My_PsLookupProcessByProcessId;
	ULONG My_PsLookupProcessByProcessId_HashValue;

	KEINITIALIZEAPC My_KeInitializeApc;
	ULONG My_KeInitializeApc_HashValue;

	KEINSERTQUEUEAPC My_KeInsertQueueApc;
	ULONG My_KeInsertQueueApc_HashValue;

	KEGETCURRENTTHREAD My_KeGetCurrentThread;
	ULONG My_KeGetCurrentThread_HashValue;

	PSGETPROCESSIMAGEFILENAME My_PsGetProcessImageFileName;
	ULONG My_PsGetProcessImageFileName_HashValue;

	PSREMOVELOADIMAGENOTIFYROUTINE My_PsRemoveLoadImageNotifyRoutine;
	ULONG My_PsRemoveLoadImageNotifyRoutine_HashValue;

	PSGETVERSION My_PsGetVersion;
	ULONG My_PsGetVerion_HashValue;

	MMISADDRESSVALID My_MmIsAddressValid;
	ULONG My_MmIsAddressValid_HashValue;

	OBOPENOBJECTBYPOINTER My_ObOpenObjectByPointer;
	ULONG My_ObOpenObjectByPointer_HashValue;

	ZWQUERYINFORMATIONTHREAD My_ZwQueryInformationThread;
	ULONG My_ZwQueryInformationThread_HashValue;

	ZWQUERYINFORMATIONPROCESS My_ZwQueryInformationProcess;
	ULONG My_ZwQueryInformationProcess_HashValue;

	PSLOOKUPPROCESSBYPROCESSID My_PsLookupThreadByThreadId;
	ULONG My_PsLookupThreadByThreadId_HashValue;

	IOTHREADTOPROCESS My_IoThreadToProcess;
	ULONG My_IoThreadToProcess_HashValue;

	IOALLOCATEMDL My_IoAllocateMdl;
	ULONG My_IoAllocateMdl_HashValue;

	MMPROBEANDLOCKPAGES My_MmProbeAndLockPages;
	ULONG My_MmProbeAndLockPages_HashValue;

	MMMAPLOCKEDPAGESSPECIFYCACHE My_MmMapLockedPagesSpecifyCache;
	ULONG My_MmMapLockedPagesSpecifyCache_HashValue;

	MMUNLOCKPAGES My_MmUnlockPages;
	ULONG My_MmUnlockPages_HashValue;

	IOFREEMDL My_IoFreeMdl;
	ULONG My_IoFreeMdl_HashValue;

	KEBUGCHECKEX My_KeBugCheckEx;
	ULONG My_KeBugCheckEx_HashValue;

	MMGETSYSTEMROUTINEADDRESS My_MmGetSystemRoutineAddress;
	ULONG My_MmGetSystemRoutineAddress_HashValue;

	RTLINITUNICODESTRING My_RtlInitUnicodeString;
	ULONG My_RtlInitUnicodeString_HashValue;

	RTLDECOMPRESSBUFFER My_RtlDecompressBuffer;
	ULONG My_RtlDecompressBuffer_HashValue;

	//WCSSTR My_Wcsstr;
	//ULONG My_Wcsstr_HashValue;


	ULONG_PTR ulEndApiSaveAddress;
	ULONG ulEndApiHashValue;
}FUNCTION_DAT,*PFUNCTION_DAT;
#pragma pack()

NTSTATUS DriverEntry(PDRIVER_OBJECT pDrvObj,PUNICODE_STRING pUniRegister);

extern PFUNCTION_DAT g_pFunctionDat;
//extern ULONG_PTR *g_ulNtoskrnlBase;
extern BOOLEAN g_bInjectProcessFlag;
extern PVOID g_pInjectBuffer;
extern ULONG g_ulInjectShellCodeLength;
//extern PVOID g_pInjectShellCode;
extern KEDELAYEXECUTIONTHREAD g_KeDelayExecutionThread;
#ifndef _WIN64
extern KEQUERYSYSTEMTIME g_KeQuerySystemTime;
#endif
extern EXSYSTEMTIMETOLOCALTIME g_ExSystemTimeToLocalTime;

#endif