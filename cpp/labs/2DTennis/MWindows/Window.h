#pragma once
#include <windows.h>


namespace Graphics
{
	namespace MWindows
	{
		class Window
		{
		private:
			HWND TwindowHandle;
		public:
			Window(LPCSTR wndName, int x = CW_USEDEFAULT, int y = 0,
				int width = CW_USEDEFAULT, int height = 0,
				DWORD windowStyle = WS_OVERLAPPEDWINDOW);
			HWND GetHWND();
		};
	}
}
