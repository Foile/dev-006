#pragma once
#include "IRobot.h"

namespace RobotWar
{
/**
	@brief —труктура, хран€ща€ координаты робота дл€ метод IRobotOperation::LookAround
*/
	struct PT 
	{
		int x,y;
	};
/**
	@brief »нтерфейс €дра игровой программы
*/
class IRobotOperation
{
public:

	
	/// ѕеремещает робота на указанное количество координат (не более 3)
	/// @param Sender - робот, который обращаетс€ к €дру. —ледует указывать this
	/// @param x - координата по x (0<=x<3)
	/// @param y - координата по y (0<=y<3)
	virtual void Move(IRobot *Sender,int x, int y) = 0;

	/// ѕозвол€ет роботу произвести выстрел на указанное рассто€ние (не более 3)
	/// @param Sender - робот, который обращаетс€ к €дру. —ледует указывать this
	/// @param x - координата по x (0<=x<3)
	/// @param y - координата по y (0<=y<3)
	virtual void Fire(IRobot *Sender,int x, int y) = 0;

    ///позвол€ет роботу получить информацию о существование других роботов в радиусе depth
	/// @param Sender - робот, который обращаетс€ к €дру. —ледует указывать this
	/// @param depth - глубина просмотра (0<=depth<3)
	/// @param CountPoints - количество элементов в буфере дл€ заполнени€ массива координат
	/// @param pPoints - массив структур PT дл€ заполнени€ координат, в которых есть объекты
	virtual void LookAround(IRobot *Sender,int depth,int CountPoints,PT *pPoints) = 0;

	///позвол€ет роботу отправить сообщение другому роботу
	/// @param Sender - робот, который обращаетс€ к €дру. —ледует указывать this
	/// @param RobotName - строка, содержаща€ им€ робота, которому пересылаетс€ сообщение
	/// @param TalkData - буфер, содержащий передаваемые другому роботу данные
	virtual void SendMsg(IRobot *Sender, char *RobotName, void *TalkData) = 0;
};

}