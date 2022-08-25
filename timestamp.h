#include <windows.h>
#include <unistd.h>
#include "beacon.h"

#define printf(format, args...) { BeaconPrintf(CALLBACK_OUTPUT, format, ## args); }

WINBASEAPI DWORD WINAPI KERNEL32$GetLastError();
WINBASEAPI HANDLE WINAPI KERNEL32$CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
WINBASEAPI BOOL WINAPI KERNEL32$SetFileTime(HANDLE hFile, FILETIME *lpCreationTime, FILETIME *lpLastAccessTime, FILETIME *lpLastWriteTime);
WINBASEAPI WINBOOL WINAPI KERNEL32$SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime);
WINBASEAPI BOOL WINAPI KERNEL32$CloseHandle(HANDLE hObject);
WINBASEAPI _CRTIMP int __cdecl MSVCRT$sscanf_s(const char *_Src,const char *_Format,...);
WINBASEAPI _CRTIMP int __cdecl MSVCRT$_access(const char *_Filename,int _AccessMode);


