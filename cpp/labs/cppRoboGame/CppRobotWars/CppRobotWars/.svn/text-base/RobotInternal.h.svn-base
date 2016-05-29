#pragma once
#include "IRobot.h"
#include "Thread.h"

using namespace RobotWar::Infrastructure;


namespace RobotWar
{
/**
	@brief Класс, реализующий обертку объекта робот, реализованного в DLL. 
	Этот класс необходим для создания потока для выполнения робота, а также 
	для хранения его специфических данных, таких как координата и здоровья
*/
class RobotInternal :
	public Thread
{
private:
	///Указатель на объект робота, класс которого реализован во внешней DLL
	IRobot *m_pGamerRobot;
	///Указатель на интерфейс ядра
	IRobotOperation *m_Kernel;
public:
	///Конструктор класса
	/// @param Robot - Указатель на объект робота, класс которого реализован во внешней DLL
	/// @param Kernel - Указатель на ядро
	RobotInternal(IRobot *Robot,IRobotOperation *Kernel);
	///деструктор
	~RobotInternal(void);
	///Возвращает имя робота, которому соответствует данный объект
	char* getName(void);
	///Обеспечивает прием сообщений, которые отправляют другие роботы (depricate)
	void ReceiveMessage(char* RobotName, void* TalkData);
	///Основной поток ядра
	void Execute(IRobotOperation*);
protected:
	/// здоровье робота
	int m_Healt;
	/// координата x робота
	int m_X;
	///координата y робота
	int m_Y;
public:

	///Возвращает здоровье робота в процентах от 0 до 100
	int getHealt(void)
	{
		return m_Healt;
	}
	///возвращает координату x робота
	int getX(void)
	{
		return m_X;
	}
	///возвращает координату y робота

	int getY(void)
	{
		return m_Y;
	}

	///Служебный метод. Возвращает интерфейс на объект, который реализован во внешней DLL
	IRobot* QueryIRobot(void)
	{
		return m_pGamerRobot;
	}

	///Метод выполнения потока робота
	void Execute() 
	{
		m_pGamerRobot->Execute(m_Kernel);
	}	

	///Установка координаты x робота
	void SetX(int x)
	{
		m_X = x;
	}
	///установка координаты y робота
	void SetY(int y)
	{
		m_Y = y;
	}

	///Уменьшение здоровья робота
	/// @param value - значение, на которое уменьшается здоровье
	void DecreaseHealth(int value)
	{
		m_Healt -= value;
	}

};

}