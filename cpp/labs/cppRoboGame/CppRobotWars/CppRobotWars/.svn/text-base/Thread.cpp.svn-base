#include "Thread.h"
#include <windows.h>
#include <process.h>

using namespace RobotWar::Infrastructure;

Thread::Thread(void)
: m_ThreadRun(false), m_hThread(0)
{
}

Thread::~Thread(void) 
{
	Stop();
}

void Thread::Suspend(void)
{
}

void Thread::Resume(void)
{
}

void Thread::Start(void)
{
	if(!m_ThreadRun)
	{
		m_hThread = (HANDLE)_beginthread((void (__cdecl *)(void *))Thread::ExecuteInternal,0,this);
		m_ThreadRun = true;
	}
}

void Thread::Stop(void)
{
	if(m_ThreadRun)
	{
		TerminateThread(m_hThread,0);
		m_ThreadRun = false;
	}
}

void Thread::ExecuteInternal(Thread *instance)
{
	instance->Execute();
}
