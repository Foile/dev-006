#include <unittest++.h>
#include <iostream>
#include "DllHelper.h"
#include "IRobot.h"
#include "RobotInternal.h"
#include "kernel.h"

using namespace RobotWar;
using namespace RobotWar::Infrastructure;
using namespace RobotWar::Kernel;

using namespace std;


TEST(ErrorLoadDLL)
{
  ;
  CHECK_THROW(DllHelper myrobotfactory("D:\\Development\\SoftEngineering\\Pavlin-Co\\cppRoboGame\\CppRobotWars\\Debug\\rabbitrobot1.dll"),LoadDllException);
}
TEST(LoadDllNormally)
{

 DllHelper myrobotfactory("D:\\Development\\SoftEngineering\\Pavlin-Co\\cppRoboGame\\CppRobotWars\\Debug\\rabbitrobot.dll");
}
TEST(InvokeCreateInstance)
{
 try
 {

  DllHelper myrobotfactory("D:\\Development\\SoftEngineering\\Pavlin-Co\\cppRoboGame\\CppRobotWars\\Debug\\rabbitrobot.dll");
  IRobot *robot = (IRobot*)myrobotfactory.CreateRobot("Robot");
  CHECK(robot != NULL);
 }
 catch(BindingProcDllException)
 {
	 cout << "!!!Binding error"<<endl;
	 CHECK(false);
 }
}
TEST(InvokeFreeInstance)
{
 try
 {

  DllHelper myrobotfactory("D:\\Development\\SoftEngineering\\Pavlin-Co\\cppRoboGame\\CppRobotWars\\Debug\\rabbitrobot.dll");
  IRobot *robot = (IRobot*)myrobotfactory.CreateRobot("Robot");
  CHECK(robot != NULL);
  myrobotfactory.FreeInstance();
 }
 catch(BindingProcDllException)
 {
	 cout << "!!!Binding error"<<endl;
	 CHECK(false);
 }
}
TEST(InitRobotInternal)
{
  DllHelper myrobotfactory("D:\\Development\\SoftEngineering\\Pavlin-Co\\cppRoboGame\\CppRobotWars\\Debug\\rabbitrobot.dll");
  IRobot *robot = (IRobot*)myrobotfactory.CreateRobot("Robot");
  RobotInternal MyRobot(robot,NULL);
  CHECK_EQUAL(100,MyRobot.getHealt());
  CHECK_EQUAL(0,MyRobot.getX());
  CHECK_EQUAL(0,MyRobot.getY());
  CHECK(strcmp(MyRobot.getName(),"Ёкспериментальный кролик")==0);
}
TEST(MoveOutOfContract)
{
	RobotWar::Kernel::Kernel *kernel = RobotWar::Kernel::Kernel::CreateKernel();
	CHECK_THROW(kernel->Move(NULL,2,2),ParametersContractError);
	CHECK_THROW(kernel->Move(NULL,-5,5),ParametersContractError);

}
int main()
{
	int Result = UnitTest::RunAllTests();
	cin.get();
	return Result;
	
}