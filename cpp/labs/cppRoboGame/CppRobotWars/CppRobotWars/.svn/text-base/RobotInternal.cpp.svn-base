#include "RobotInternal.h"

using namespace RobotWar;

RobotInternal::RobotInternal(IRobot *pRobot,IRobotOperation *Kernel)
: m_Healt(100)
, m_X(0)
, m_Y(0)
, m_pGamerRobot(pRobot)
, m_Kernel(Kernel)
{
}

RobotInternal::~RobotInternal(void)
{
	delete m_pGamerRobot;
}

char* RobotInternal::getName(void)
{
	return m_pGamerRobot->getName();
}

void RobotInternal::ReceiveMessage(char* RobotName, void* TalkData)
{
	return m_pGamerRobot->ReceiveMessage(RobotName,TalkData);
}

void RobotInternal::Execute(IRobotOperation *Engine)
{
	//вот здесь надо создать новый поток, в котором и следует вызвать Execute
}
