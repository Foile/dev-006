#pragma once
#include "idiskapi.h"
#include <gmock/gmock.h>
class FakeWin32ApiImpl :
	public IDiskApi
{
public:
	
	MOCK_METHOD7(CreateFile,HANDLE(LPCTSTR lpFileName,
            DWORD dwDesiredAccess,
            DWORD dwShareMode,
            LPSECURITY_ATTRIBUTES lpSecurityAttributes,
            DWORD dwCreationDisposition,
            DWORD dwFlagsAndAttributes,
            HANDLE hTemplateFile));
  
  MOCK_METHOD5(WriteFile,BOOL(
               HANDLE hFile,
               LPCVOID lpBuffer,
               DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten,
               LPOVERLAPPED lpOverlapped));

  MOCK_METHOD5(ReadFile,BOOL(
               HANDLE hFile,
               LPVOID lpBuffer,
               DWORD nNumberOfBytesToRead,
               LPDWORD lpNumberOfBytesRead,
               LPOVERLAPPED lpOverlapped));
  MOCK_METHOD1(CloseHandle,
	           BOOL(HANDLE));
};

