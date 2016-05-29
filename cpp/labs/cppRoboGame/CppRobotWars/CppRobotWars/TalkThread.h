#pragma once
#include "iRobot.h"
#include "Thread.h"
namespace RobotWar
{
	namespace Kernel
	{
/**
*	@brief ����� ������ ��� ������������ ������ IRobotOperation::SendMsg()
*/
		class TalkThread :
			public RobotWar::Infrastructure::Thread
			{
			public:
				TalkThread(void);
				~TalkThread(void);
				TalkThread(IRobot *robot,char* RobotName, void* TalkData);
			private:
				///��� ������, ������� ���������� ���������
				char* m_SenderName;
				///������, ������� ���������� ������� ������
				void* m_TalkData;
				///�����, ������� ������ ������� ���������
				IRobot *m_ReceiverRobot;
			public:
				///����� ���������� ������
				void Execute(void);
		};
	}

}