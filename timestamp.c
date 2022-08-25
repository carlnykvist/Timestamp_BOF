#include "timestamp.h"

void go(char *args, int length) {

    datap parser;
    BeaconDataParse(&parser, args, length);
    CHAR *file = BeaconDataExtract(&parser, NULL);
    CHAR *date = BeaconDataExtract(&parser, NULL);
    SYSTEMTIME st;
    FILETIME ft;

    if(!MSVCRT$_access(file, F_OK) == 0) {
        printf("[-] File %s does not exist", file);
        return;
    } 

    
    MSVCRT$sscanf_s(date, "%d-%d-%d %d:%d:%d", &st.wYear, &st.wMonth, &st.wDay, &st.wHour, &st.wMinute, &st.wSecond);

    if (!KERNEL32$SystemTimeToFileTime(&st, &ft)) {
        printf("[-] Error: %d\n", KERNEL32$GetLastError());
    }

    HANDLE hFile = KERNEL32$CreateFileA((LPCSTR)file, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, 4, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        KERNEL32$SetFileTime(hFile, NULL, NULL, &ft);
        printf("[+] Date has been modified")
    }

    else
    {
        printf("[-] Error: %d\n", KERNEL32$GetLastError());
    }

    KERNEL32$CloseHandle(hFile);

}