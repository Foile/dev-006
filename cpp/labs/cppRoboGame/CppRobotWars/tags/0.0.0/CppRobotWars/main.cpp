#include <windows.h>
#include "resource.h"


LRESULT CALLBACK HandleEvent(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR,int nCmdShow)
{
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.hbrBackground = CreateHatchBrush(HS_CROSS,RGB(255,0,0));
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hIconSm = wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_MAIN));
	wc.hInstance = hInstance;
	wc.lpfnWndProc = HandleEvent;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAIN);
	wc.style = 0;
	wc.lpszClassName = "ROBOT::MAIN";

	if(!RegisterClassEx(&wc)) return 1;

	HWND hWndMain = CreateWindow("ROBOT::MAIN","Битва роботов. Многопоточная редакция 1.0",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		HWND_DESKTOP, NULL,hInstance, NULL);
	ShowWindow(hWndMain,nCmdShow);

	MSG msg;
	while(GetMessage(&msg,0,0,0))
		DispatchMessage(&msg);
	return msg.wParam;

}