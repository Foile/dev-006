#include "OpenFileDialog.h"

OpenFileDialog::OpenFileDialog(HWND owner)
{
	
		_filename.lStructSize = sizeof(_filename);
		_filename.hwndOwner = owner;
		_filename.hInstance=0;
		_filename.lpstrFilter = "DLL Robot Files\0*.dll\0ALL files you wanted\0*.*\0";
		_filename.lpstrCustomFilter =0;
		_filename.nMaxCustFilter=0;
		_filename.nFilterIndex=1;
		_filename.lpstrFile=_bufferForFileEditControl;
		_filename.lpstrFile[0] = '\0';
		_filename.nMaxFile=MAX_STRING_LENGTH;
		_filename.lpstrFileTitle = _bufferForFileName;
		_filename.lpstrFileTitle[0] = '\0';
		_filename.nMaxFileTitle = MAX_STRING_LENGTH;
		_filename.lpstrInitialDir=NULL;
		_filename.lpstrTitle = "Please, load robot's *.dll algorithm file!!!";
		_filename.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER | OFN_ENABLESIZING | OFN_SHAREAWARE;
		_filename.lpstrDefExt = "dll";
		_filename.pvReserved = NULL;
		_filename.dwReserved = 0;
		_filename.FlagsEx = 0;
}
char* OpenFileDialog::getFileName()
{
		return _filename.lpstrFile;
}
char* OpenFileDialog::getOnlyFileName()
{
		return _filename.lpstrFileTitle;
}
void OpenFileDialog::setFilter(char* filter)
{
		bool notFindTwoZero = true;
		bool findOneZero = false;
		int i=0;
		while (notFindTwoZero)
		{
			_filter[i]=filter[i];
			if (_filter[i]=='\0')
			{
				if (findOneZero)
					notFindTwoZero = false;
				findOneZero = true;
			}
			else
				findOneZero = false;
			
			i++;			
		}
		_filename.lpstrFilter = _filter;
}
bool OpenFileDialog::show()
{
		return GetOpenFileName(&_filename) != 0;
}