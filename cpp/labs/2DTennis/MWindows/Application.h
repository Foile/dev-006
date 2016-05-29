#pragma once
#include <vector>
#include <map>
#include <windows.h>
#include "Window.h"
#include "../Graphic/MenuHelper.h"

using namespace std;


namespace Graphics
{
	namespace MWindows
	{
		class Application
		{
		private:
			map <int,Window*> T_windows;
			//------Singletone------------------------------------
			static Application *T_pointer;
			HINSTANCE T_instance;
			Application(HINSTANCE hInst);
			Application(Application &source);
			Application& operator = (Application &source);
			WNDCLASSEX T_wc;
		public:
			//------Singletone--------------------------------
			static Application& Inst();
			static void Init(HINSTANCE hInst);
			static LRESULT CALLBACK MainWindowProc(HWND wnd,UINT msg,WPARAM wParam,LPARAM lParam);
			Window* CreateNewWindow(LPCSTR name, int x, int y, int width, int height, Window* parent = 0, DWORD style = WS_OVERLAPPEDWINDOW);
			~Application(void);
			LPCSTR GetBaseClass();
			HINSTANCE GetModuleInstance();

		};
	}
}