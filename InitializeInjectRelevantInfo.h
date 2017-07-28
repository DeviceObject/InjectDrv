#ifndef __INITIALIZE_INJECT_RELEVANT_INFO__
#define __INITIALIZE_INJECT_RELEVANT_INFO__

#define DELAY_ONE_MICROSECOND	(-10)
#define DELAY_ONE_MILLISECOND	(DELAY_ONE_MICROSECOND*1000)
#define DELAY_ONE_SECOND		(DELAY_ONE_MILLISECOND*1000)

#ifndef POWER_FAILURE_SIMULATE
#define POWER_FAILURE_SIMULATE 0x000000E5
#endif


typedef struct _INJECT_THREAD 
{
	LIST_ENTRY NextThread;

}INJECT_THREAD,*PINJECT_THREAD;

typedef struct _INJECT_PROCESS
{
	LIST_ENTRY NextProcess;

}INJECT_PROCESS,*PINJECT_PROCESS;

typedef struct _INJECT_TARGET_INFO
{
	HANDLE hInjectPid;
	ULONG ulHashValue;
	PVOID pEThread;
}INJECT_TARGET_INFO,*PINJECT_TARGET_INFO;
typedef struct _SYSTEM_VERSION
{
	ULONG ulMajorVersion;
	ULONG ulMinorVersion;
	ULONG ulBuildNumber;
	PUNICODE_STRING unStrCSDVersion;
}SYSTEM_VERSION,*PSYSTEM_VERSION;
typedef struct _WINDOWS_VERSION
{
#ifndef _WIN64
	ULONG_PTR ulReserved:20;
#else
	ULONG_PTR ulReserved:52;
#endif
	ULONG_PTR bIsUnknow:1;
	ULONG_PTR bIsWindows2000:1;
	ULONG_PTR bIsWindowsXp:1;
	ULONG_PTR bIsWindows2003:1;
	ULONG_PTR bIsWindowsVista:1;
	ULONG_PTR bIsWindows7:1;
	ULONG_PTR bIsWindows2008:1;
	ULONG_PTR bIsWindows8:1;
	ULONG_PTR bIsWindows81:1;
	ULONG_PTR bIsWindows10:1;
	ULONG_PTR bIsWindows2012:1;
	ULONG_PTR bIs64Bit:1;
}WINDOWS_VERSION,*PWINDOWS_VERSION;
typedef struct _INJECT_RELEVANT_OFFSET
{
	//Process
	ULONG_PTR ulOffsetPeb;
	ULONG_PTR ulOffsetName;
	ULONG_PTR ulOffsetFlink;
	ULONG_PTR ulOffsetResv;
	ULONG_PTR ulOffsetThreadListHead;
	ULONG_PTR ulOffsetPid;

	//Thread
	ULONG_PTR ulOffsetThreadListEntry;
	ULONG_PTR ulOffsetSuspendCount;
	ULONG_PTR ulOffsetCrossThreadFlags;
	ULONG_PTR ulOffsetCid;
	ULONG_PTR ulOffsetTrapFrame;
	ULONG_PTR ulOffsetTeb;
	ULONG_PTR ulOffsetAlerted;
	ULONG_PTR ulOffsetAlertable;
	ULONG_PTR ulOffsetApcState;

	//PEB
	ULONG_PTR ulOffsetPebLdr;
	ULONG_PTR ulOffsetPebModuleListEntry;

	//Teb
	ULONG_PTR ulOffsetActivationContextStackPointer;
	
	WINDOWS_VERSION WindowsVersion;
}INJECT_RELEVANT_OFFSET,*PINJECT_RELEVANT_OFFSET;

extern INJECT_RELEVANT_OFFSET g_InjectRelevantOffset;

NTSTATUS IsWindows64Bits(PVOID pCurProcess);
BOOLEAN InitializeWindows2k(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
BOOLEAN InitializeWindowsXp(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
BOOLEAN InitializeWindows2003(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
NTSTATUS InitializeWindows7(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
NTSTATUS InitializeWindows8(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
NTSTATUS InitializeWindows8_1(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
NTSTATUS InitializeWindows10(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);
BOOLEAN InitializeInjectInformation(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset);


#endif
