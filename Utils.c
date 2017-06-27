#include "DrvCfg.h"
#include "Utils.h"

#ifndef _WIN64
void __stdcall CleanZero(PUCHAR pCleanBuffer,ULONG ulLength)
#else
void __fastcall CleanZero(PUCHAR pCleanBuffer,ULONG ulLength)
#endif
{
	ULONG ulCnt;

	ulCnt = 0;

	while (ulCnt < ulLength)
	{
		if (*(pCleanBuffer + ulCnt) != 0)
		{
			*(pCleanBuffer + ulCnt) = 0;
		}
		ulCnt++;
	}
}
#ifndef _WIN64
PCHAR __stdcall MyMemcpy(PCHAR pDst,PCHAR pSrc,ULONG ulLength)
#else
PCHAR __fastcall MyMemcpy(PCHAR pDst,PCHAR pSrc,ULONG ulLength)
#endif
{
	ULONG ulCnt;

	ulCnt = 0;
	while (ulCnt < ulLength)
	{
		*pDst++ = *pSrc++;
		ulCnt++;
	}
	return pDst;
}
#ifndef _WIN64
ULONG __stdcall CalcHashValue(char *szApiName)
#else
ULONG __fastcall CalcHashValue(char *szApiName)
#endif
{
	USHORT ulHashValue;
	ULONG ulTmp,ulOrValue;
	int i;
	CHAR szTmp;

	ulHashValue = 1;
	ulOrValue = 0;

	for (i = 0;i < my_strlen(szApiName);i++)
	{
		szTmp = szApiName[i];
		ulHashValue += szTmp;
		ulOrValue += ulHashValue;
	}
	ulTmp = ulOrValue << 0x10;
	ulTmp |= ulHashValue;
	return ulTmp;
}
#ifndef _WIN64
int __stdcall My_memicmp(char *src,char *dest,int size)
#else
int __fastcall My_memicmp(char *src,char *dest,int size)
#endif
{
	char *src_tmp = src;
	char *dest_tmp = dest;
	while(size--)
	{
		if((*src_tmp==*dest_tmp)||
			(((*src_tmp)-'A'+'a')==*dest_tmp)
			||*src_tmp==((*dest_tmp)-'A'+'a'))
		{
			src_tmp++;
			dest_tmp++;
			continue;
		}
		return -1;
	}
	return 0;
}
#ifndef _WIN64
char *__stdcall My_stristr(char *src,char *dest)
#else
char *__fastcall My_stristr(char *src,char *dest)
#endif
{
	int x_len;
	int i;
	int ret;
	char *src_tmp = src;
	char *dest_tmp = dest;
	x_len=my_strlen(dest_tmp);
	i=my_strlen(src_tmp);

	if(i<x_len)	return 0;

	i-=(x_len-1);
	while(i--)
	{
		ret=My_memicmp(src_tmp++,dest_tmp,x_len);
		if(!ret) return --src_tmp;
	}
	return 0;
}
#ifndef _WIN64
int __stdcall my_strlen(char *str)
#else
int __fastcall my_strlen(char *str)
#endif
{
	int i;
	char* str_tmp = str;
	i=0;
	while(*str_tmp++)i++;
	return i;
}
#ifndef _WIN64
int __stdcall my_strcmp(char *src,char *dest)
#else
int __fastcall my_strcmp(char *src,char *dest)
#endif
{
	char *src_tmp = src;
	char *dest_tmp = dest;
	while(*src_tmp == *dest_tmp)
	{
		if(*src_tmp)
		{
			src_tmp++;
			dest_tmp++;
			continue;
		}
		return 0;
	}
	return -1;
}
#ifndef _WIN64
PCHAR __stdcall MyStrLower(PCHAR pSrc)
#else
PCHAR __fastcall MyStrLower(PCHAR pSrc)
#endif
{
	PCHAR pTmp;
	pTmp = pSrc;
	if (*pTmp++)
	{
		if (*pTmp >= 'A' && *pTmp <= 'Z')
		{
			*pTmp = *pTmp - 0x20;
		}
	}
	return pSrc;
}