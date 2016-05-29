#include "TalkThread.h"

using namespace RobotWar::Kernel;

TalkThread::TalkThread(void)
: m_SenderName(NULL)
, m_TalkData(NULL)
{
}

TalkThread::~TalkThread(void)
{
}

RobotWar::Kernel::TalkThread::TalkThread(IRobot *Robot,char* RobotName, void* TalkData)
:m_ReceiverRobot(Robot) 
, m_SenderName(RobotName)
, m_TalkData(TalkData)
{
}

void RobotWar::Kernel::TalkThread::Execute(void)
{
	m_ReceiverRobot->ReceiveMessage(m_SenderName,m_TalkData);
}
