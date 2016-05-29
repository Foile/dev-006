#pragma once

//#include "IRobotOperation.h"

namespace RobotWar
{

class IRobotOperation;


/**
*	@brief	Интерфейс IRobot реализуется классом пользователя, который должен быть расположен во внешней динамической библиотекой, загружаемой по требованию пользователя
*/
class IRobot
{
public:

	
	/// Получение имени робота. Возвращает имя робота, определенное пользователем
	virtual char* getName(void) = 0;
	

	///Прием сообщеия. Вызывается ядром программы, когда другой робот посылает сообщение роботу, реализующему данный метод интерфейса
	virtual void ReceiveMessage(char* RobotName, void* TalkData) = 0;

	///Метод выполнения потока робота. Этот метод вызывается при создании для робота отдельного потока
	virtual void Execute(IRobotOperation *Engine)=0;
};

}