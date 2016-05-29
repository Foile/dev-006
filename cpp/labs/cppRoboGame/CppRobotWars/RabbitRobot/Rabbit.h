#pragma once
#include "IRobot.h"
#include "IRobotOperation.h"

using namespace RobotWar;

class Rabbit :
	public IRobot
{
public:
	Rabbit(void);
	~Rabbit(void);
	// ������� ��� ������
	char* getName(void);
	void ReceiveMessage(char* RobotName, void* TalkData);
	void Execute(IRobotOperation *Engine);
};
