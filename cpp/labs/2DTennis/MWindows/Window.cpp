#include "Window.h"
#include <windows.h>
#include "Application.h"

using namespace Graphics::MWindows;

Window::Window(LPCSTR wndName, int x, int y,
		int width, int height,
		DWORD windowStyle)
{	
	HINSTANCE hInstance = Application::Inst().GetModuleInstance();
	TwindowHandle = CreateWindowEx(0,Application::Inst().GetBaseClass(),wndName,windowStyle,x,y,
						width,height,0,0,hInstance,0);
	if (TwindowHandle)
		ShowWindow(TwindowHandle,SW_SHOW);
}

HWND Window::GetHWND()
{
	return TwindowHandle;
}

