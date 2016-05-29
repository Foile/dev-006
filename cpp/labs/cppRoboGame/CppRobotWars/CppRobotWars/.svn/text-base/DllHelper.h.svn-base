#pragma once
#include <windows.h>
#include "MyException.h"
#include "IRobotFactory.h"
namespace RobotWar
{
/**
*	@brief Общий класс исключения при работе с динамически загружаемой библиотекой
*/
	class DllException : public RobotWarException
	{
	};
/**
*	@brief Класс исключения, которое выбрасывается при невозможности загрузки DLL
*   классом DllHelper
*/
	class LoadDllException : public DllException
	{
	};
/**
*	@brief Класс исключения, которое выбрасывается при невозможности связывания экспортируемой процедуры
*/
	class BindingProcDllException: public DllException
	{
	};
namespace Infrastructure
 {
/**
 @brief Класс загрузчик Dll роботов и создания экземпляра класса, реализующего интерфейс IRobot
*/
	 class DllHelper : public IRobotFactory
	{
	private:
		HMODULE m_hModule;
		char* m_DllObjectClassName;
	public:
		DllHelper(char* Path);
		~DllHelper(void);

		IRobot* CreateRobot(char* DllObjectClassName);

		void FreeInstance(void);
	};
 }
}