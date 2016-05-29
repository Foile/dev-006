#pragma once

#include "IRobot.h"

namespace RobotWar
{
/**
	@brief ��������� ������� ������� �������. ��������������� �� ������� �������� �������
*/
class IRobotFactory
{
public:
	///�������� ������
	/// @param Name - ��� ������������ ������
	virtual IRobot* CreateRobot(char* Name) = 0 ;
};

}
