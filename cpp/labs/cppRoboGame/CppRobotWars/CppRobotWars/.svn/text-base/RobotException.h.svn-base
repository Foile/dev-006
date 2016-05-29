#pragma once

#include "MyException.h"
/**
	@brief Суперкласс для исключений, связанных с роботами, реализуемых во внешних DLL
*/
class RobotException : public RobotWarException
{
public:
	RobotException(void);
	~RobotException(void);
};

/**
*	@brief Исключений, которое выбрасывается при невозможности загрузить DLL, 
    указанную пользователем при создании объекта класса DllHelper
*/
class LoadRobotException :public RobotException
{
public:
	LoadRobotException(void);
	~LoadRobotException(void);
};
