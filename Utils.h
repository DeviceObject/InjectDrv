#ifndef __UTILS_H__
#define __UTILS_H__

#ifndef _WIN64
void __stdcall CleanZero(PUCHAR pCleanBuffer,ULONG ulLength);
#else
void __fastcall CleanZero(PUCHAR pCleanBuffer,ULONG ulLength);
#endif

#ifndef _WIN64
	PCHAR __stdcall MyMemcpy(PCHAR pDst,PCHAR pSrc,ULONG ulLength);
#else
	PCHAR __fastcall MyMemcpy(PCHAR pDst,PCHAR pSrc,ULONG ulLength);
#endif

#ifndef _WIN64
	ULONG __stdcall CalcHashValue(char *szApiName);
#else
	ULONG __fastcall CalcHashValue(char *szApiName);
#endif

#ifndef _WIN64
	int __stdcall My_memicmp(char *src,char *dest,int size);
#else
	int __fastcall My_memicmp(char *src,char *dest,int size);
#endif

#ifndef _WIN64
	char *__stdcall My_stristr(char *src,char *dest);
#else
	char *__fastcall My_stristr(char *src,char *dest);
#endif

#ifndef _WIN64
	int __stdcall my_strlen(char *str);
#else
	int __fastcall my_strlen(char *str);
#endif

#ifndef _WIN64
	int __stdcall my_strcmp(char *src,char *dest);
#else
	int __fastcall my_strcmp(char *src,char *dest);
#endif

#ifndef _WIN64
	PCHAR __stdcall MyStrLower(PCHAR pSrc);
#else
	PCHAR __fastcall MyStrLower(PCHAR pSrc);
#endif

#endif