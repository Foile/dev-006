#include "Win32ApiImpl.h"


Win32ApiImpl::Win32ApiImpl(void)
{
}


Win32ApiImpl::~Win32ApiImpl(void)
{
}

 HANDLE Win32ApiImpl::CreateFile(
            LPCTSTR lpFileName,
            DWORD dwDesiredAccess,
            DWORD dwShareMode,
            LPSECURITY_ATTRIBUTES lpSecurityAttributes,
            DWORD dwCreationDisposition,
            DWORD dwFlagsAndAttributes,
            HANDLE hTemplateFile
 )
{
	return ::CreateFile(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);
}

 BOOL Win32ApiImpl::WriteFile(
               HANDLE hFile,
               LPCVOID lpBuffer,
               DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten,
               LPOVERLAPPED lpOverlapped
)
 {
	 return ::WriteFile(hFile,lpBuffer,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);
 }
  BOOL Win32ApiImpl::ReadFile(
               HANDLE hFile,
               LPVOID lpBuffer,
               DWORD nNumberOfBytesToRead,
               LPDWORD lpNumberOfBytesRead,
               LPOVERLAPPED lpOverlapped
)
 {
	 return ::ReadFile(hFile,lpBuffer,nNumberOfBytesToRead,lpNumberOfBytesRead,lpOverlapped);
 }
  BOOL Win32ApiImpl::CloseHandle(HANDLE handle)
  {
	  return ::CloseHandle(handle);
  }