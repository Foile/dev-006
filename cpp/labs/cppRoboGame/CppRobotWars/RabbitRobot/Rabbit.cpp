#include "Rabbit.h"
#include "resource.h"
#include <windows.h>

using namespace RobotWar;

extern HINSTANCE hInstanceDLL;

LRESULT CALLBACK DlgProc(HWND hWnd,UINT msg,WPARAM wParam, LPARAM lParam);

Rabbit::Rabbit(void)
{
}

Rabbit::~Rabbit(void)
{
}

// вернуть имя робота
char* Rabbit::getName(void)
{
	return "Экспериментальный кролик";
}

void Rabbit::ReceiveMessage(char* RobotName, void* TalkData)
{
}

void Rabbit::Execute(IRobotOperation *Engine)
{
    char *cmd="top";
	DialogBox(::hInstanceDLL,MAKEINTRESOURCE(IDD_DIALOG1),NULL,(DLGPROC)DlgProc);
	bool talk=false;
	while(1)
	{		
	 Engine->Move(this,2,2);
	 if(!talk)
		{
		 Engine->SendMsg(this,"ExperimentalMouse",cmd);
		 talk = true;
		}
	 }
}
LRESULT CALLBACK DlgProc(HWND hWnd,UINT msg,WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hWnd,1);return TRUE;
		case IDCANCEL:
			EndDialog(hWnd,0);return TRUE;
		}			
	}
	return FALSE;
}