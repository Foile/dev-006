#pragma once
#include "iRobot.h"
#include "Thread.h"
namespace RobotWar
{
	namespace Kernel
	{
/**
*	@brief  ласс потока дл€ асинхронного метода IRobotOperation::SendMsg()
*/
		class TalkThread :
			public RobotWar::Infrastructure::Thread
			{
			public:
				TalkThread(void);
				~TalkThread(void);
				TalkThread(IRobot *robot,char* RobotName, void* TalkData);
			private:
				///им€ робота, который отправл€ет сообщение
				char* m_SenderName;
				///данные, которые передаютс€ другому роботу
				void* m_TalkData;
				///–обот, который должен прин€ть сообщение
				IRobot *m_ReceiverRobot;
			public:
				///метод выполнени€ потока
				void Execute(void);
		};
	}

}