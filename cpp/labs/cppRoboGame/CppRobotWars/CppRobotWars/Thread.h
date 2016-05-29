#pragma once
#include <windows.h>

namespace RobotWar
{
 namespace Infrastructure
{
/**
	@brief  ласс потока. »спользуетс€ дл€ организации потоковых объектов
*/
class Thread
{
public:
	///конструктор класса
	Thread(void);
	///деструктор
	virtual ~Thread(void);
	///метод выполнени€ потока
	virtual void Execute(void) = 0;
	///приостановка потока
	virtual void Suspend(void);
	///возобновление потока
	virtual void Resume(void);
	///запуск потока
	virtual void Start(void);
	///останов потока
	virtual void Stop(void);
private:
	///дескриптор потока
	HANDLE m_hThread;
	///служебный метод выполнени€ потока. »спользуетс€ дл€ адаптации Win32API 
	static void ExecuteInternal(Thread *);
	///флаг, определ€ющий запущен поток или нет
	bool m_ThreadRun;
};
}
}