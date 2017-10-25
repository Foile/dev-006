#pragma once
#include <Windows.h>

class IDiskApi
{
public:

 virtual	HANDLE CreateFile(
            LPCTSTR lpFileName,
            DWORD dwDesiredAccess,
            DWORD dwShareMode,
            LPSECURITY_ATTRIBUTES lpSecurityAttributes,
            DWORD dwCreationDisposition,
            DWORD dwFlagsAndAttributes,
            HANDLE hTemplateFile
 ) = 0;

 virtual BOOL  WriteFile(
              HANDLE hFile,
               LPCVOID lpBuffer,
               DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten,
               LPOVERLAPPED lpOverlapped
) = 0;
 virtual BOOL ReadFile(
               HANDLE hFile,
               LPVOID lpBuffer,
               DWORD nNumberOfBytesToRead,
               LPDWORD lpNumberOfBytesRead,
               LPOVERLAPPED lpOverlapped
)=0;
virtual BOOL CloseHandle(HANDLE handle) 
= 0;
};

