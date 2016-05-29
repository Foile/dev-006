#pragma once
#include "irobot.h"

using namespace RobotWar;

class Mouse :
	public IRobot
{
	char *m_TalkData;
	enum {left,top,right,bottom} m_Direction;
public:
	Mouse(void);
	~Mouse(void);
	char* getName(void);
	void ReceiveMessage(char* RobotName, void* TalkData);
	void Execute(IRobotOperation *Engine);
};
