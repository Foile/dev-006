#include <windows.h>
#include <vector>
#include "resource.h"
#include "openfiledialog.h"
#include "sampleview.h"
#include "kernel.h"
#include "dllhelper.h"
#include "robotinternal.h"

SampleView *pView = NULL;

using namespace RobotWar;
using namespace RobotWar::Infrastructure;

RobotWar::Kernel::Kernel *pKernel = NULL;

vector<IRobotFactory*> DllStorage;

LRESULT CALLBACK HandleEvent(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		pView = new SampleView(hWnd);
		pKernel = RobotWar::Kernel::Kernel::CreateKernel();
		pKernel->OnTalk.Attach(pView);
		pKernel->OnMove.Attach(pView);
		pKernel->OnNewRobot.Attach(pView);
		return 0;
	case WM_DESTROY:
		if(pView) delete pView;
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case ID_LOADROBOT:
				{
				 OpenFileDialog dlg(hWnd);
				 if(!dlg.show()) return 0;
				  IRobotFactory *pDll = new DllHelper(dlg.getFileName());
				  DllStorage.push_back(pDll);
				  IRobot *robot = pDll->CreateRobot("Robot");
				  RobotInternal *pRobotInternal = new RobotInternal(robot,pKernel);
				  pKernel->AddRobot(pRobotInternal);
				 return 0;
				}
			case ID_RUNGAME:
				{
					pKernel->Start();
					return 0;
				}
			case ID_QUIT:
				{
					PostQuitMessage(0);
					return 0;
				}
			}
		}
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR,int nCmdShow)
{
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hIconSm = wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_MAIN));
	wc.hInstance = hInstance;
	wc.lpfnWndProc = HandleEvent;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAIN);
	wc.style = CS_OWNDC;
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