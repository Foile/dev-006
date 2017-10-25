#pragma once
#include "idiskapi.h"
class Win32ApiImpl :
	public IDiskApi
{
public:
	Win32ApiImpl(void);
	~Win32ApiImpl(void);
	virtual	HANDLE CreateFile(
            LPCTSTR lpFileName,
            DWORD dwDesiredAccess,
            DWORD dwShareMode,
            LPSECURITY_ATTRIBUTES lpSecurityAttributes,
            DWORD dwCreationDisposition,
            DWORD dwFlagsAndAttributes,
            HANDLE hTemplateFile
 );

 virtual BOOL WriteFile(
               HANDLE hFile,
               LPCVOID lpBuffer,
               DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten,
               LPOVERLAPPED lpOverlapped
);
 virtual BOOL ReadFile(
               HANDLE hFile,
               LPVOID lpBuffer,
               DWORD nNumberOfBytesToRead,
               LPDWORD lpNumberOfBytesRead,
               LPOVERLAPPED lpOverlapped
);
 virtual BOOL CloseHandle(HANDLE handle);
};

