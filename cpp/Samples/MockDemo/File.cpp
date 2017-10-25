#include "File.h"
#include "WinApiException.h"

File::File(IDiskApi *aApi) : api(aApi)
{
  hHandle = 0;	
}


File::~File(void)
{
	if(hHandle == 0) return;

	if(!api->CloseHandle(hHandle))
		throw WinApiException(::GetLastError());
}


void File::Open(char* FileName)
{
	hHandle = api->CreateFile(FileName,GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	//hHandle = (void*) 0xF0FFF;//эмуляция бага в коде
	if(hHandle == INVALID_HANDLE_VALUE)
		throw WinApiException(::GetLastError());
}



void File::Write(char* Buffer, int size)
{
	DWORD actualWriteSize;
	if(!api->WriteFile(hHandle,Buffer,size,&actualWriteSize,NULL))
		throw WinApiException(::GetLastError());
}


void File::Read(char* Buffer, int size)
{
	DWORD actualReadSize;
	if(!api->ReadFile(hHandle,Buffer,size,&actualReadSize,NULL))
		throw WinApiException(::GetLastError());
}
