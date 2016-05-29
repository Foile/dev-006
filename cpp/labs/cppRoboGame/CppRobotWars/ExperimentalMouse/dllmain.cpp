#include "mouse.h"
#include <windows.h>

using namespace RobotWar;


HINSTANCE hInstanceDLL = 0;
Mouse *myRobot = NULL;

BOOL WINAPI DllMain(HINSTANCE hInstanceDLL,DWORD fdwReason,
  void*)
{
	::hInstanceDLL = hInstanceDLL;
  return true;
}

//������� DLL, ���������� ��� ������������� ������

#pragma comment(linker,"/export:CreateRobot=?CreateRobot@@YA_NPAPAX@Z")
 __declspec(dllexport) bool  CreateRobot(void **MyRobot)
{

	*MyRobot = new Mouse;
	return true;
}

//������ DLL, ���������� ��� ����������� ������
#pragma comment(linker,"/export:DestroyRobot=?DestroyRobot@@YA_NXZ")
 __declspec(dllexport) bool   DestroyRobot()
{
	if(myRobot) delete myRobot;
	return true;
}