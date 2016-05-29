#include "Application.h"
#include <windows.h>
#include "Window.h"
#include "../Graphic/Controller.h"
#include "../Graphic/MenuHelper.h"

using namespace Graphics::MWindows;

LRESULT CALLBACK Application::MainWindowProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		{
			break;
		}
	
	case WM_CLOSE:
	case WM_DESTROY:
		{
			delete Controller::GetGraphics();
			PostQuitMessage(0);
			break;
		}
	

	case WM_COMMAND:
		{
			break;
		}
	case WM_LBUTTONDOWN:
		{
			switch (wParam)
			{
				case MK_LBUTTON:
				{
					int x,y;
					x = LOWORD(lParam);
					y = HIWORD(lParam);
					if (x > 100 && x < 500 && y > 100 && y < 150)
					{
						MenuHelper::ClickMenu(1);
					}
					if (x > 100 && x < 500 && y > 200 && y < 250)
					{
						MenuHelper::ClickMenu(2);
					}
					if (x > 100 && x < 500 && y > 300 && y < 350)
					{
						MenuHelper::ClickMenu(3);
					}
					break;
				}
			}
			
		}
	case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_LEFT:
					{
						Controller::left();
						break;
					}
				case VK_RIGHT:
					{
						Controller::right();
						break;
					}
				case VK_UP:
					{
						Controller::up();
						break;
					}
				case VK_DOWN:
					{
						Controller::down();
						break;
					}
				case VK_SPACE:
					{
						if (!Controller::getShoot())
							Controller::shoot();
						break;
					}
				case VK_ESCAPE:
					{
						ObjectStorage::Inst().SetCurrentScene(GameScene::MAIN_MENU);
						break;
					}
			}
			break;
		}
	case WM_KEYUP:
		{
			switch (wParam)
			{
				case VK_LEFT:
					{
						Controller::stop();
						break;
					}
				case VK_RIGHT:
					{
						Controller::stop();
						break;
					}
				case VK_UP:
					{
						Controller::stop2();
						break;
					}
				case VK_DOWN:
					{
						Controller::stop2();
						break;
					}
			}
			break;
		}
	default:
		return DefWindowProc(wnd,msg,wParam,lParam);
	}

	return 0;
}


Application* Application::T_pointer = 0;

Application& Application::Inst()
{
	return *T_pointer;
}

Application& Application::operator =(Application &source)
{
	return Inst();
}

Application::Application(HINSTANCE hInst)
{
	T_instance = hInst;
	memset(&T_wc, 0, sizeof(WNDCLASSEX));
	T_wc.cbSize = sizeof(WNDCLASSEX);
	T_wc.hInstance = T_instance;
	T_wc.lpfnWndProc = MainWindowProc;
	T_wc.lpszClassName = "2DTennis";
	T_wc.style = CS_OWNDC;
	T_wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	T_wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	T_wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	T_wc.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
	if (!RegisterClassEx(&T_wc))
	{
		char mess[100] = "Cannot register class: ";
		strcat(mess,"Application");
		MessageBox(NULL,(LPCTSTR)mess,(LPCTSTR)"ERROR",MB_OK);
		exit(1);
	}
}

Application::~Application(void)
{
}



void Application::Init(HINSTANCE hInst)
{
	T_pointer = new Application(hInst);
}




Window* Application::CreateNewWindow(LPCSTR name, int x, int y, int width, int height, Window * parent,
								   DWORD style)
{
	Window *wnd = new Window(name, x, y, width, height, style );
	T_windows[T_windows.size()] = wnd;		
	return wnd;
}


LPCSTR Application::GetBaseClass()
{
	return T_wc.lpszClassName;
}

HINSTANCE Application::GetModuleInstance()
{
	return T_instance;
}

