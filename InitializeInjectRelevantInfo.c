#include "DrvCfg.h"
#include "KernelApi.h"
#include "Utils.h"
#include "InitializeInjectRelevantInfo.h"

INJECT_RELEVANT_OFFSET g_InjectRelevantOffset = {0};

NTSTATUS IsWindows64Bits(PVOID pCurProcess)
{
	NTSTATUS Status;
	HANDLE hProcess;
	ULONG_PTR ulIsWow64Process;
	ULONG ulRetLength;

	ulIsWow64Process = 0;
	Status = g_pFunctionDat->My_ObOpenObjectByPointer(pCurProcess,OBJ_KERNEL_HANDLE,NULL,PROCESS_ALL_ACCESS,NULL,KernelMode,&hProcess);
	if (NT_ERROR(Status))
	{
		return Status;
	}
	Status = g_pFunctionDat->My_ZwQueryInformationProcess(hProcess,ProcessWow64Information,&ulIsWow64Process,sizeof(ULONG_PTR),&ulRetLength);
	if (NT_ERROR(Status))
	{
		return Status;
	}
	if (ulIsWow64Process)
	{
		return 0x64;
	}
	else
	{
		return 0x86;
	}
	return Status;
}
BOOLEAN InitializeWindows2k(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
	pInjectRelevantOffset->WindowsVersion.bIsWindows2000 = TRUE;
	pInjectRelevantOffset->ulOffsetPeb = 0x00;
	pInjectRelevantOffset->ulOffsetName = 0x01FC;
	pInjectRelevantOffset->ulOffsetFlink = 0x00;
	pInjectRelevantOffset->ulOffsetThreadListHead = 0x00;
	pInjectRelevantOffset->ulOffsetPid = 0x00;

	pInjectRelevantOffset->ulOffsetSuspendCount = 0x00;
	pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x00;
	pInjectRelevantOffset->ulOffsetCid = 0x00;
	pInjectRelevantOffset->ulOffsetTrapFrame = 0x00;
	pInjectRelevantOffset->ulOffsetThreadListEntry = 0x00;

	pInjectRelevantOffset->ulOffsetAlertable = 0x0158;
	pInjectRelevantOffset->ulOffsetApcState = 0x0034;
	
	return TRUE;
}
BOOLEAN InitializeWindowsXp(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
	pInjectRelevantOffset->WindowsVersion.bIsWindowsXp = TRUE;
	pInjectRelevantOffset->ulOffsetPeb = 0x1B0;
	pInjectRelevantOffset->ulOffsetName = 0x174;
	pInjectRelevantOffset->ulOffsetFlink = 0x88;
	pInjectRelevantOffset->ulOffsetThreadListHead = 0x190;
	pInjectRelevantOffset->ulOffsetPid = 0x84;

	pInjectRelevantOffset->ulOffsetSuspendCount = 0x1b9;
	pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x248;
	pInjectRelevantOffset->ulOffsetCid = 0x1ec;
	pInjectRelevantOffset->ulOffsetTrapFrame = 0x134;
	pInjectRelevantOffset->ulOffsetThreadListEntry = 0x22c;
	pInjectRelevantOffset->ulOffsetTeb = 0x20;
	pInjectRelevantOffset->ulOffsetAlertable = 0x0164;
	pInjectRelevantOffset->ulOffsetApcState = 0x0034;

	pInjectRelevantOffset->ulOffsetPebLdr = 0x0c;
	pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x0c;

	pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x1A8;

	return TRUE;
}
BOOLEAN InitializeWindows2003(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
	pInjectRelevantOffset->WindowsVersion.bIsWindows2003 = TRUE;
	pInjectRelevantOffset->ulOffsetPeb = 0x00;
	pInjectRelevantOffset->ulOffsetName = 0x00;
	pInjectRelevantOffset->ulOffsetFlink = 0x00;
	pInjectRelevantOffset->ulOffsetThreadListHead = 0x00;
	pInjectRelevantOffset->ulOffsetPid = 0x00;

	pInjectRelevantOffset->ulOffsetSuspendCount = 0x00;
	pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x00;
	pInjectRelevantOffset->ulOffsetCid = 0x00;
	pInjectRelevantOffset->ulOffsetTrapFrame = 0x00;
	pInjectRelevantOffset->ulOffsetThreadListEntry = 0x00;
	pInjectRelevantOffset->ulOffsetTeb = 0x20;
	pInjectRelevantOffset->ulOffsetAlertable = 0x0154;
	pInjectRelevantOffset->ulOffsetApcState = 0x0034;

	pInjectRelevantOffset->ulOffsetPebLdr = 0x0c;
	pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x0c;

	pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x1A8;


	return TRUE;
}
NTSTATUS InitializeWindows7(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	NTSTATUS Status;

	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIsWindows7 = TRUE;
	Status = IsWindows64Bits(g_pFunctionDat->My_IoGetCurrentProcess());
	if (Status == 0x86)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
		pInjectRelevantOffset->ulOffsetPeb = 0x01a8;
		pInjectRelevantOffset->ulOffsetName = 0x016c;
		pInjectRelevantOffset->ulOffsetFlink = 0x00b8;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x188;
		pInjectRelevantOffset->ulOffsetPid = 0xB4;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x188;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x280;
		pInjectRelevantOffset->ulOffsetCid = 0x22c;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x128;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x268;
		pInjectRelevantOffset->ulOffsetTeb = 0x88;
		pInjectRelevantOffset->ulOffsetAlerted = 0x3A;
		pInjectRelevantOffset->ulOffsetAlertable = 0x3C;
		pInjectRelevantOffset->ulOffsetApcState = 0x40;

		pInjectRelevantOffset->ulOffsetPebLdr = 0x0c;
		pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x0c;

		pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x1A8;
		return TRUE;
	}
	else if (Status == 0x64)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = TRUE;
		pInjectRelevantOffset->ulOffsetPeb = 0x330 + 0x08;
		pInjectRelevantOffset->ulOffsetName = 0x2d8 + 0x08;
		pInjectRelevantOffset->ulOffsetFlink = 0x188;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x30;
		pInjectRelevantOffset->ulOffsetPid = 0x180;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x26c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x448;
		pInjectRelevantOffset->ulOffsetCid = 0x3b0;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x1d8;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x2f8;
		pInjectRelevantOffset->ulOffsetTeb = 0x0b8;
		pInjectRelevantOffset->ulOffsetAlerted = 0x4A;
		pInjectRelevantOffset->ulOffsetAlertable = 0x4C;
		pInjectRelevantOffset->ulOffsetApcState = 0x50;

		pInjectRelevantOffset->ulOffsetPebLdr = 0x18;
		pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x10;

		pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x2c8;
		return TRUE;
	}
	else
	{
	}
	if (NT_ERROR(Status))
	{
		return FALSE;
	}
	return Status;
}
NTSTATUS InitializeWindows8_1(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	NTSTATUS Status;

	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIsWindows81 = TRUE;
	Status = IsWindows64Bits(g_pFunctionDat->My_IoGetCurrentProcess());
	if (Status == 0x86)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
		pInjectRelevantOffset->ulOffsetPeb = 0x140;
		pInjectRelevantOffset->ulOffsetName = 0x170;
		pInjectRelevantOffset->ulOffsetFlink = 0x0b8;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x194;
		pInjectRelevantOffset->ulOffsetPid = 0xB4;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x18c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x3b8;
		pInjectRelevantOffset->ulOffsetCid = 0x364;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x06c;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x39c;
		pInjectRelevantOffset->ulOffsetTeb = 0xa8;
		pInjectRelevantOffset->ulOffsetAlerted = 0x56;
		pInjectRelevantOffset->ulOffsetAlertable = 0x58;
		pInjectRelevantOffset->ulOffsetApcState = 0x70;


		pInjectRelevantOffset->ulOffsetPebLdr = 0x0c;
		pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x0c;
		pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x1A8;
		return TRUE;
	}
	else if (Status == 0x64)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = TRUE;
		pInjectRelevantOffset->ulOffsetPeb = 0x330;
		pInjectRelevantOffset->ulOffsetName = 0x2d8;
		pInjectRelevantOffset->ulOffsetFlink = 0x188;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x300;
		pInjectRelevantOffset->ulOffsetPid = 0x180;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x26c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x448;
		pInjectRelevantOffset->ulOffsetCid = 0x3b0;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x1d8;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x030;
		pInjectRelevantOffset->ulOffsetAlerted = 0x72;
		pInjectRelevantOffset->ulOffsetAlertable = 0x74;
		pInjectRelevantOffset->ulOffsetApcState = 0x98;
		return TRUE;
	}
	else
	{
	}
	if (NT_ERROR(Status))
	{
		return FALSE;
	}
	return Status;
}
NTSTATUS InitializeWindows8(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	NTSTATUS Status;

	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIsWindows8 = TRUE;
	Status = IsWindows64Bits(g_pFunctionDat->My_IoGetCurrentProcess());
	if (Status == 0x86)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
		pInjectRelevantOffset->ulOffsetPeb = 0x140;
		pInjectRelevantOffset->ulOffsetName = 0x170;
		pInjectRelevantOffset->ulOffsetFlink = 0x0b8;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x194;
		pInjectRelevantOffset->ulOffsetPid = 0xB4;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x18c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x268;
		pInjectRelevantOffset->ulOffsetCid = 0x214;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x06c;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x24c;
		pInjectRelevantOffset->ulOffsetTeb = 0xa8;
		pInjectRelevantOffset->ulOffsetAlerted = 0x56;
		pInjectRelevantOffset->ulOffsetAlertable = 0x58;
		pInjectRelevantOffset->ulOffsetApcState = 0x70;


		pInjectRelevantOffset->ulOffsetPebLdr = 0x0c;
		pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x0c;
		pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x1A8;
		return TRUE;
	}
	else if (Status == 0x64)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = TRUE;
		pInjectRelevantOffset->ulOffsetPeb = 0x330;
		pInjectRelevantOffset->ulOffsetName = 0x2d8;
		pInjectRelevantOffset->ulOffsetFlink = 0x188;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x300;
		pInjectRelevantOffset->ulOffsetPid = 0x180;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x26c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x448;
		pInjectRelevantOffset->ulOffsetCid = 0x3b0;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x1d8;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x030;
		pInjectRelevantOffset->ulOffsetAlerted = 0x72;
		pInjectRelevantOffset->ulOffsetAlertable = 0x74;
		pInjectRelevantOffset->ulOffsetApcState = 0x98;
		return TRUE;
	}
	else
	{
	}
	if (NT_ERROR(Status))
	{
		return FALSE;
	}
	return Status;
}
NTSTATUS InitializeWindows10(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	NTSTATUS Status;

	if (NULL == pInjectRelevantOffset)
	{
		return FALSE;
	}
	pInjectRelevantOffset->WindowsVersion.bIsWindows10 = TRUE;
	Status = IsWindows64Bits(g_pFunctionDat->My_IoGetCurrentProcess());
	if (Status == 0x86)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = FALSE;
		pInjectRelevantOffset->ulOffsetPeb = 0x144;
		pInjectRelevantOffset->ulOffsetName = 0x174;
		pInjectRelevantOffset->ulOffsetFlink = 0x0b8;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x198;
		pInjectRelevantOffset->ulOffsetPid = 0xB4;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x18c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x3c8;
		pInjectRelevantOffset->ulOffsetCid = 0x374;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x06c;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x3ac;
		pInjectRelevantOffset->ulOffsetTeb = 0xa8;

		pInjectRelevantOffset->ulOffsetPebLdr = 0x0c;
		pInjectRelevantOffset->ulOffsetPebModuleListEntry = 0x0c;

		pInjectRelevantOffset->ulOffsetActivationContextStackPointer = 0x1A8;
		return TRUE;
	}
	else if (Status == 0x64)
	{
		pInjectRelevantOffset->WindowsVersion.bIs64Bit = TRUE;
		pInjectRelevantOffset->ulOffsetPeb = 0x330;
		pInjectRelevantOffset->ulOffsetName = 0x2d8;
		pInjectRelevantOffset->ulOffsetFlink = 0x188;
		pInjectRelevantOffset->ulOffsetThreadListHead = 0x300;
		pInjectRelevantOffset->ulOffsetPid = 0x180;

		pInjectRelevantOffset->ulOffsetSuspendCount = 0x26c;
		pInjectRelevantOffset->ulOffsetCrossThreadFlags = 0x448;
		pInjectRelevantOffset->ulOffsetCid = 0x3b0;
		pInjectRelevantOffset->ulOffsetTrapFrame = 0x1d8;
		pInjectRelevantOffset->ulOffsetThreadListEntry = 0x030;
		return TRUE;
	}
	else
	{
	}
	if (NT_ERROR(Status))
	{
		return FALSE;
	}
	return Status;
}
BOOLEAN InitializeInjectInformation(PINJECT_RELEVANT_OFFSET pInjectRelevantOffset)
{
	SYSTEM_VERSION SystemVersion;
	
	CleanZero((PUCHAR)pInjectRelevantOffset,sizeof(INJECT_RELEVANT_OFFSET));
	CleanZero((PUCHAR)&SystemVersion,sizeof(SYSTEM_VERSION));
	g_pFunctionDat->My_PsGetVersion(&SystemVersion.ulMajorVersion, \
		&SystemVersion.ulMinorVersion, \
		&SystemVersion.ulBuildNumber, \
		SystemVersion.unStrCSDVersion);
	if (SystemVersion.ulMajorVersion == 0x0A && SystemVersion.ulMinorVersion == 0)
	{
		if (InitializeWindows10(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
	}
	else if (SystemVersion.ulMajorVersion == 6 && SystemVersion.ulMinorVersion == 3)
	{
		if (InitializeWindows8_1(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
	}
	else if (SystemVersion.ulMajorVersion == 6 && SystemVersion.ulMinorVersion == 2)
	{
		if (InitializeWindows8(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
	}
	else if (SystemVersion.ulMajorVersion == 6 && SystemVersion.ulMinorVersion == 1)
	{
		if (InitializeWindows7(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
	}
	else if (SystemVersion.ulMajorVersion == 6 && SystemVersion.ulMinorVersion == 0)
	{
		if (SystemVersion.ulBuildNumber == 6001)
		{
			//DbgPrint(" Sp 1\r\n");
		}
		else if (SystemVersion.ulBuildNumber == 6002)
		{
			//DbgPrint(" Sp 2\r\n");
		}
		else
		{
			//DbgPrint("\r\n");
		}

	}
	else if (SystemVersion.ulMajorVersion == 5 && SystemVersion.ulMinorVersion == 2)
	{
		if (InitializeWindows2003(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
		
	}
	else if (SystemVersion.ulMajorVersion == 5 && SystemVersion.ulMinorVersion == 1)
	{
		if (InitializeWindowsXp(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
	}
	else if (SystemVersion.ulMajorVersion == 5 && SystemVersion.ulMinorVersion == 0)
	{
		if (InitializeWindows2k(pInjectRelevantOffset) == TRUE)
		{
			return TRUE;
		}
		return FALSE;
	}
	else if (SystemVersion.ulMajorVersion == 4 && SystemVersion.ulMinorVersion == 0)
	{
	}
	return FALSE;
}
