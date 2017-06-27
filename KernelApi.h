#ifndef __KERNEL_API_H__
#define __KERNEL_API_H__

#define PROCESS_TERMINATE                  (0x0001)  
#define PROCESS_CREATE_THREAD              (0x0002)  
#define PROCESS_SET_SESSIONID              (0x0004)  
#define PROCESS_VM_OPERATION               (0x0008)  
#define PROCESS_VM_READ                    (0x0010)  
#define PROCESS_VM_WRITE                   (0x0020)  
#define PROCESS_DUP_HANDLE                 (0x0040)  
#define PROCESS_CREATE_PROCESS             (0x0080)  
#define PROCESS_SET_QUOTA                  (0x0100)  
#define PROCESS_SET_INFORMATION            (0x0200)  
#define PROCESS_QUERY_INFORMATION          (0x0400)  
#define PROCESS_SUSPEND_RESUME             (0x0800)  
#define PROCESS_QUERY_LIMITED_INFORMATION  (0x1000)  

NTSTATUS ZwQueryInformationThread(__in HANDLE ThreadHandle,
                                  __in THREADINFOCLASS ThreadInformationClass,
                                  __out_bcount(ThreadInformationLength) PVOID ThreadInformation,
                                  __in ULONG ThreadInformationLength,
                                  __out_opt PULONG ReturnLength);

NTSTATUS ZwQueryInformationProcess(__in HANDLE ProcessHandle,
                                   __in PROCESSINFOCLASS ProcessInformationClass,
                                   __out PVOID ProcessInformation,
                                   __in ULONG ProcessInformationLength,
                                   __out_opt PULONG ReturnLength);

typedef enum _SYSTEM_INFORMATION_CLASS {
    SystemBasicInformation,				// 0
    SystemProcessorInformation,			// 1	obsolete...delete
    SystemPerformanceInformation,			// 2
    SystemTimeOfDayInformation,			// 3
    SystemPathInformation,				// 4
    SystemProcessInformation,			// 5
    SystemCallCountInformation,			// 6
    SystemDeviceInformation,			// 7
    SystemProcessorPerformanceInformation,		// 8
    SystemFlagsInformation,				// 9
    SystemCallTimeInformation,			// 10
    SystemModuleInformation,			// 11
    SystemLocksInformation,				// 12
    SystemStackTraceInformation,			// 13
    SystemPagedPoolInformation,			// 14
    SystemNonPagedPoolInformation,			// 15
    SystemHandleInformation,			// 16
    SystemObjectInformation,			// 17
    SystemPageFileInformation,			// 18
    SystemVdmInstemulInformation,			// 19
    SystemVdmBopInformation,			// 20
    SystemFileCacheInformation,			// 21
    SystemPoolTagInformation,			// 22
    SystemInterruptInformation,			// 23
    SystemDpcBehaviorInformation,			// 24
    SystemFullMemoryInformation,			// 25
    SystemLoadGdiDriverInformation,			// 26
    SystemUnloadGdiDriverInformation,		// 27
    SystemTimeAdjustmentInformation,		// 28
    SystemSummaryMemoryInformation,			// 29
    SystemMirrorMemoryInformation,			// 30
    SystemPerformanceTraceInformation,		// 31
    SystemObsolete0,				// 32
    SystemExceptionInformation,			// 33
    SystemCrashDumpStateInformation,		// 34
    SystemKernelDebuggerInformation,		// 35
    SystemContextSwitchInformation,			// 36
    SystemRegistryQuotaInformation,			// 37
    SystemExtendServiceTableInformation,		// 38
    SystemPrioritySeperation,			// 39
    SystemVerifierAddDriverInformation,		// 40
    SystemVerifierRemoveDriverInformation,		// 41
    SystemProcessorIdleInformation,			// 42
    SystemLegacyDriverInformation,			// 43
    SystemCurrentTimeZoneInformation,		// 44
    SystemLookasideInformation,			// 45
    SystemTimeSlipNotification,			// 46
    SystemSessionCreate,				// 47
    SystemSessionDetach,				// 48
    SystemSessionInformation,			// 49
    SystemRangeStartInformation,			// 50
    SystemVerifierInformation,			// 51
    SystemVerifierThunkExtend,			// 52
    SystemSessionProcessInformation,		// 53
    SystemLoadGdiDriverInSystemSpace,		// 54
    SystemNumaProcessorMap,				// 55
    SystemPrefetcherInformation,			// 56
    SystemExtendedProcessInformation,		// 57
    SystemRecommendedSharedDataAlignment,		// 58
    SystemComPlusPackage,				// 59
    SystemNumaAvailableMemory,			// 60
    SystemProcessorPowerInformation,		// 61
    SystemEmulationBasicInformation,		// 62
    SystemEmulationProcessorInformation,		// 63
    SystemExtendedHandleInformation,		// 64
    SystemLostDelayedWriteInformation,		// 65
    SystemBigPoolInformation,			// 66
    SystemSessionPoolTagInformation,		// 67
    SystemSessionMappedViewInformation,		// 68
    SystemHotpatchInformation,			// 69
    SystemObjectSecurityMode,			// 70
    SystemWatchdogTimerHandler,			// 71
    SystemWatchdogTimerInformation,			// 72
    SystemLogicalProcessorInformation,		// 73
    SystemWow64SharedInformation,			// 74
    SystemRegisterFirmwareTableInformationHandler,	// 75
    SystemFirmwareTableInformation,			// 76
    SystemModuleInformationEx,			// 77
    SystemVerifierTriageInformation,		// 78
    SystemSuperfetchInformation,			// 79
    SystemMemoryListInformation,			// 80
    SystemFileCacheInformationEx,			// 81
    MaxSystemInfoClass  // MaxSystemInfoClass should always be the last enum
} SYSTEM_INFORMATION_CLASS;

typedef struct _SYSTEM_MODULE_INFORMATION_ENTRY {
    HANDLE Section;
    PVOID MappedBase;
    PVOID Base;
    ULONG Size;
    ULONG Flags;
    USHORT LoadOrderIndex;
    USHORT InitOrderIndex;
    USHORT LoadCount;
    USHORT PathLength;
    CHAR ImageName[256];
} SYSTEM_MODULE_INFORMATION_ENTRY, *PSYSTEM_MODULE_INFORMATION_ENTRY;

typedef struct _SYSTEM_MODULE_INFORMATION {
    ULONG Count;
    SYSTEM_MODULE_INFORMATION_ENTRY Module[1];
} SYSTEM_MODULE_INFORMATION, *PSYSTEM_MODULE_INFORMATION;

typedef struct _SYSTEM_PROCESS_INFORMATION {
    ULONG NextEntryOffset;
    ULONG NumberOfThreads;
    LARGE_INTEGER SpareLi1;
    LARGE_INTEGER SpareLi2;
    LARGE_INTEGER SpareLi3;
    LARGE_INTEGER CreateTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER KernelTime;
    UNICODE_STRING ImageName;
    KPRIORITY BasePriority;
    HANDLE UniqueProcessId;
    HANDLE InheritedFromUniqueProcessId;
    ULONG HandleCount;
    ULONG SessionId;
    ULONG_PTR PageDirectoryBase;
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivatePageCount;
    LARGE_INTEGER ReadOperationCount;
    LARGE_INTEGER WriteOperationCount;
    LARGE_INTEGER OtherOperationCount;
    LARGE_INTEGER ReadTransferCount;
    LARGE_INTEGER WriteTransferCount;
    LARGE_INTEGER OtherTransferCount;
} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

typedef struct _SYSTEM_THREAD_INFORMATION {
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER CreateTime;
    ULONG WaitTime;
    PVOID StartAddress;
    CLIENT_ID ClientId;
    KPRIORITY Priority;
    LONG BasePriority;
    ULONG ContextSwitches;
    ULONG ThreadState;
    ULONG WaitReason;
} SYSTEM_THREAD_INFORMATION, *PSYSTEM_THREAD_INFORMATION;

typedef struct _THREAD_BASIC_INFORMATION {
    NTSTATUS ExitStatus;
    PNT_TIB TebBaseAddress;
    CLIENT_ID ClientId;
    KAFFINITY AffinityMask;
    KPRIORITY Priority;
    KPRIORITY BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

typedef enum _KAPC_ENVIRONMENT {
    OriginalApcEnvironment,
    AttachedApcEnvironment,
    CurrentApcEnvironment,
    InsertApcEnvironment
} KAPC_ENVIRONMENT;

//VOID KeInitializeApc(__out PRKAPC Apc,
//                     __in PRKTHREAD Thread,
//                     __in KAPC_ENVIRONMENT Environment,
//                     __in PKKERNEL_ROUTINE KernelRoutine,
//                     __in_opt PKRUNDOWN_ROUTINE RundownRoutine,
//                     __in_opt PKNORMAL_ROUTINE NormalRoutine,
//                     __in_opt KPROCESSOR_MODE ProcessorMode,
//                     __in_opt PVOID NormalContext);
//BOOLEAN KeInsertQueueApc(__inout PRKAPC Apc,
//                         __in_opt PVOID SystemArgument1,
//                         __in_opt PVOID SystemArgument2,
//                         __in KPRIORITY Increment);

#define PAGE_NOACCESS          0x01     
#define PAGE_READONLY          0x02     
#define PAGE_READWRITE         0x04     
#define PAGE_WRITECOPY         0x08     
#define PAGE_EXECUTE           0x10     
#define PAGE_EXECUTE_READ      0x20     
#define PAGE_EXECUTE_READWRITE 0x40     
#define PAGE_EXECUTE_WRITECOPY 0x80     
#define PAGE_GUARD            0x100     
#define PAGE_NOCACHE          0x200     
#define PAGE_WRITECOMBINE     0x400     
#define MEM_COMMIT           0x1000     
#define MEM_RESERVE          0x2000     
#define MEM_DECOMMIT         0x4000     
#define MEM_RELEASE          0x8000     
#define MEM_FREE            0x10000     
#define MEM_PRIVATE         0x20000     
#define MEM_MAPPED          0x40000     
#define MEM_RESET           0x80000     
#define MEM_TOP_DOWN       0x100000     
#define MEM_WRITE_WATCH    0x200000     
#define MEM_PHYSICAL       0x400000     
#define MEM_ROTATE         0x800000     
#define MEM_LARGE_PAGES  0x20000000     
#define MEM_4MB_PAGES    0x80000000     
#define SEC_FILE           0x800000     
#define SEC_IMAGE         0x1000000     
#define SEC_PROTECTED_IMAGE  0x2000000     
#define SEC_RESERVE       0x4000000     
#define SEC_COMMIT        0x8000000     
#define SEC_NOCACHE      0x10000000     
#define SEC_WRITECOMBINE 0x40000000     
#define SEC_LARGE_PAGES  0x80000000     
#define MEM_IMAGE         SEC_IMAGE     
#define WRITE_WATCH_FLAG_RESET 0x01

#ifndef _WIN64
NTSTATUS ZwQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, \
										 PVOID SystemInformation, \
										 ULONG SystemInformationLength, \
										 PULONG ReturnLength);
typedef PWCHAR (__stdcall *WCSSTR)(const WCHAR *Str,const WCHAR *SubStr);
typedef VOID (__stdcall *MMUNMAPLOCKEDPAGES)(PVOID BaseAddress,PMDL MemoryDescriptorList);
typedef PVOID (__stdcall *MMMAPLOCKEDPAGES)(PMDL MemoryDescriptorList,KPROCESSOR_MODE AccessMode);
typedef VOID (__stdcall *MMBUILDMDLFORNONPAGEDPOOL)(PMDLX MemoryDescriptorList);
typedef PMDL (__stdcall *MMCREATEMDL)(PMDL MemoryDescriptorList,PVOID Base,SIZE_T Length);
typedef PVOID (__stdcall *PSGETCURRENTPROCESS)(void);
typedef PVOID (__stdcall *KEGETCURRENTTHREAD)(void);
typedef BOOLEAN (__stdcall *KEINSERTQUEUEAPC)(PKAPC Apc,PVOID SystemArg1,PVOID SystemArg2,KPRIORITY Increment);
//typedef VOID (__stdcall *PKKERNEL_ROUTINE)(PKAPC Apc,PVOID *NormalRoutine,PVOID *NormalContext,PVOID *SystemArgument1,PVOID *SystemArgument2);
typedef VOID (__stdcall *KEINITIALIZEAPC)(PKAPC Apc,PETHREAD Thread,PVOID Environment,PVOID KernelRoutine, \
					 PVOID RundownRoutine,PVOID NormalRoutine,KPROCESSOR_MODE ProcessorMode,PVOID NormalContext);
typedef VOID (__stdcall *KEUNSTACKDETACHPROCESS)(PVOID ApcState);
typedef NTSTATUS (__stdcall *ZWALLOCATEVIRTUALMEMORY)(HANDLE ProcessHandle,PVOID *BaseAddress,ULONG_PTR ZeroBits,PSIZE_T RegionSize,ULONG AllocationType,ULONG Protect);
typedef VOID (__stdcall *KESTACKATTACHPROCESS)(PVOID Process,PVOID ApcState);
typedef PVOID (__stdcall *IOGETCURRENTPROCESS)(void);
typedef NTSTATUS (__stdcall *KEWAITFORSINGLEOBJECT)(PVOID Object,KWAIT_REASON WaitReason,KPROCESSOR_MODE WaitMode,BOOLEAN Alertable,PLARGE_INTEGER Timeout);
typedef VOID (__stdcall *OBDEREFERENCEOBJECT)(PVOID Object);
typedef NTSTATUS (__stdcall *ZWCLOSE)(HANDLE Handle);
typedef NTSTATUS (__stdcall *OBREFERENCEOBJECTBYHANDLE)(HANDLE Handle,ACCESS_MASK DesiredAccess,POBJECT_TYPE ObjectType,KPROCESSOR_MODE AccessMode, \
										   PVOID *Object,POBJECT_HANDLE_INFORMATION HandleInformation);
typedef NTSTATUS (__stdcall *PSCREATESYSTEMTHREAD)(PHANDLE ThreadHandle,ULONG DesiredAccess,POBJECT_ATTRIBUTES ObjectAttributes, \
									  HANDLE ProcessHandle,PCLIENT_ID ClientId,PKSTART_ROUTINE StartRoutine,PVOID StartContext);
typedef NTSTATUS (__stdcall *PSLOOKUPPROCESSBYPROCESSID)(HANDLE ProcessId,PVOID *Process);
typedef NTSTATUS (__stdcall *PSTERMINATESYSTEMTHREAD)(NTSTATUS ExitStatus);
typedef NTSTATUS (__stdcall *PSSETLOADIMAGENOTIFYROUTINE)(PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine);
typedef PVOID (__stdcall *EXALLOCATEPOOLWITHTAG)(POOL_TYPE PoolType,SIZE_T NumberOfBytes,ULONG Tag);
typedef NTSTATUS (__stdcall *ZWQUERYSYSTEMINFORMATION)(SYSTEM_INFORMATION_CLASS SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength);
typedef VOID (__stdcall *EXFREEPOOLWITHTAG)(PVOID P,ULONG Tag);
typedef BOOLEAN (__stdcall *Function_Entry)(PVOID pNtoskrnlBase,EXALLOCATEPOOLWITHTAG MyExAllocatePoolWithTag);
typedef PUCHAR (__stdcall *PSGETPROCESSIMAGEFILENAME)(PVOID Process);
typedef NTSTATUS (__stdcall *PSREMOVELOADIMAGENOTIFYROUTINE)(PVOID NotifyRoutine);


#else
NTSTATUS ZwQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, \
										 PVOID SystemInformation, \
										 ULONG SystemInformationLength, \
										 PULONG ReturnLength);
typedef PWCHAR (__fastcall *WCSSTR)(const WCHAR *Str,const WCHAR *SubStr);
typedef VOID (__fastcall *MMUNMAPLOCKEDPAGES)(PVOID BaseAddress,PMDL MemoryDescriptorList);
typedef PVOID (__fastcall *MMMAPLOCKEDPAGES)(PMDL MemoryDescriptorList,KPROCESSOR_MODE AccessMode);
typedef VOID (__fastcall *MMBUILDMDLFORNONPAGEDPOOL)(PMDLX MemoryDescriptorList);
typedef PMDL (__fastcall *MMCREATEMDL)(PMDL MemoryDescriptorList,PVOID Base,SIZE_T Length);
typedef PVOID (__fastcall *PSGETCURRENTPROCESS)(void);
typedef PVOID (__fastcall *KEGETCURRENTTHREAD)(void);
typedef BOOLEAN (__fastcall *KEINSERTQUEUEAPC)(PKAPC Apc,PVOID SystemArg1,PVOID SystemArg2,KPRIORITY Increment);
//typedef VOID (__fastcall *PKKERNEL_ROUTINE)(PVOID Apc,PVOID *NormalRoutine,PVOID *NormalContext,PVOID *SystemArgument1,PVOID *SystemArgument2);
typedef VOID (__fastcall *KEINITIALIZEAPC)(PKAPC Apc,PETHREAD Thread,PVOID Environment,PVOID KernelRoutine, \
								PVOID RundownRoutine,PVOID NormalRoutine,KPROCESSOR_MODE ProcessorMode,PVOID NormalContext);
typedef VOID (__fastcall *KEUNSTACKDETACHPROCESS)(PVOID ApcState);
typedef NTSTATUS (__fastcall *ZWALLOCATEVIRTUALMEMORY)(HANDLE ProcessHandle,PVOID *BaseAddress,ULONG_PTR ZeroBits,PSIZE_T RegionSize,ULONG AllocationType,ULONG Protect);
typedef VOID (__fastcall *KESTACKATTACHPROCESS)(PVOID Process,PVOID ApcState);
typedef PVOID (__fastcall *IOGETCURRENTPROCESS)(void);
typedef NTSTATUS (__fastcall *KEWAITFORSINGLEOBJECT)(PVOID Object,KWAIT_REASON WaitReason,KPROCESSOR_MODE WaitMode,BOOLEAN Alertable,PLARGE_INTEGER Timeout);
typedef VOID (__fastcall *OBDEREFERENCEOBJECT)(PVOID Object);
typedef NTSTATUS (__fastcall *ZWCLOSE)(HANDLE Handle);
typedef NTSTATUS (__fastcall *OBREFERENCEOBJECTBYHANDLE)(HANDLE Handle,ACCESS_MASK DesiredAccess,POBJECT_TYPE ObjectType,KPROCESSOR_MODE AccessMode, \
														PVOID *Object,POBJECT_HANDLE_INFORMATION HandleInformation);
typedef NTSTATUS (__fastcall *PSCREATESYSTEMTHREAD)(PHANDLE ThreadHandle,ULONG DesiredAccess,POBJECT_ATTRIBUTES ObjectAttributes, \
												   HANDLE ProcessHandle,PCLIENT_ID ClientId,PKSTART_ROUTINE StartRoutine,PVOID StartContext);
typedef NTSTATUS (__fastcall *PSLOOKUPPROCESSBYPROCESSID)(HANDLE ProcessId,PVOID *Process);
typedef NTSTATUS (__fastcall *PSTERMINATESYSTEMTHREAD)(NTSTATUS ExitStatus);
typedef NTSTATUS (__fastcall *PSSETLOADIMAGENOTIFYROUTINE)(PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine);
typedef PVOID (__fastcall *EXALLOCATEPOOLWITHTAG)(POOL_TYPE PoolType,SIZE_T NumberOfBytes,ULONG Tag);
typedef NTSTATUS (__fastcall *ZWQUERYSYSTEMINFORMATION)(SYSTEM_INFORMATION_CLASS SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength);
typedef VOID (__fastcall *EXFREEPOOLWITHTAG)(PVOID P,ULONG Tag);
typedef BOOLEAN (__fastcall *Function_Entry)(PVOID pNtoskrnlBase,EXALLOCATEPOOLWITHTAG MyExAllocatePoolWithTag);
typedef PUCHAR (__fastcall *PSGETPROCESSIMAGEFILENAME)(PVOID Process);
typedef NTSTATUS (__fastcall *PSREMOVELOADIMAGENOTIFYROUTINE)(PVOID NotifyRoutine);
#endif


#endif