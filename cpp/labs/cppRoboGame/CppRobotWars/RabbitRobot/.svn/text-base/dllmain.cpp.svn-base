#include <windows.h>
#include "Rabbit.h"


using namespace RobotWar;

Rabbit *myRobot=NULL;
HINSTANCE hInstanceDLL = 0;

BOOL WINAPI DllMain(HINSTANCE hInstanceDLL,DWORD fdwReason,
  void*)
{
	::hInstanceDLL = hInstanceDLL;
  return true;
}

//функция DLL, вызываемая для инициализации робота

#pragma comment(linker,"/export:CreateRobot=?CreateRobot@@YA_NPAPAX@Z")
 __declspec(dllexport) bool  CreateRobot(void **MyRobot)
{

	myRobot = new Rabbit;
	*MyRobot = myRobot;
	return true;
}

//функци DLL, вызываемая при уничтожении робота
#pragma comment(linker,"/export:DestroyRobot=?DestroyRobot@@YA_NXZ")
 __declspec(dllexport) bool   DestroyRobot()
{
	if(myRobot) delete myRobot;
	return true;
}