#include "DllHelper.h"

using namespace RobotWar;
using namespace RobotWar::Infrastructure;

#pragma warning(disable : 4996)

DllHelper::DllHelper(char* Path): m_hModule(NULL),m_DllObjectClassName(NULL)
{
	if(!(m_hModule = LoadLibrary(Path)))  
		throw LoadDllException();
}

DllHelper::~DllHelper(void)
{
 
if(m_hModule) 		
 FreeLibrary(m_hModule);
}

IRobot* DllHelper::CreateRobot(char* DllObjectClassName)
{
 typedef void (*FPointer)(void**);

	if(!DllObjectClassName) throw RobotWarException();
 m_DllObjectClassName = new char[strlen(DllObjectClassName)+1];
 strcpy(m_DllObjectClassName,DllObjectClassName);
 char *Prefix = "Create";
 char *FullInvokeName = new char[strlen(m_DllObjectClassName)+1+strlen(Prefix)];
 strcpy(FullInvokeName,Prefix);
 strcat(FullInvokeName,m_DllObjectClassName);

 FPointer ptrfCreateObject = (FPointer) GetProcAddress(m_hModule,FullInvokeName);
 if(!ptrfCreateObject) throw BindingProcDllException();
 
 void *ptrInterface;
 ptrfCreateObject(&ptrInterface);
 delete[]FullInvokeName;
 return (IRobot*)ptrInterface;
 
}

void RobotWar::Infrastructure::DllHelper::FreeInstance(void)
{
typedef void (*FPointer)();

 if(m_DllObjectClassName)
 {
	char *Prefix = "Destroy";
	char *FullInvokeName = new char[strlen(m_DllObjectClassName)+1+strlen(Prefix)];
	strcpy(FullInvokeName,Prefix);
	strcat(FullInvokeName,m_DllObjectClassName);

	 FPointer ptrfDestroyObject = (FPointer) GetProcAddress(m_hModule,FullInvokeName);
	if(!ptrfDestroyObject) throw BindingProcDllException();
 
	ptrfDestroyObject();
	delete[]FullInvokeName;
 }
}
