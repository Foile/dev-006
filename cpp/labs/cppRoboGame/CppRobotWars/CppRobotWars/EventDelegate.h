#pragma once
#include "imvc.h"
#include "robotinternal.h"
#include <list>

using namespace std;


namespace RobotWar
{
 	namespace MVC
	{
/**
*	@brief ����� ����� ��� ���������� �������. ����������� ���� ����� ��� 
*   �������� ����� ������� ���������� ������� ���� ���������
*/
		class Event
		{
		private:
			///��������� �� ������, ������� �������� ���������� �������
			RobotWar::RobotInternal  *  m_SenderRobot;
		public:
			///��������� ��������� �� ������ ������ ��� ����������� ���������
			///�������������� ������ � ��������� � ����������� ������
			RobotWar::RobotInternal*  GetSender() const { return m_SenderRobot;}
			///����������� �� ���������
			Event() : m_SenderRobot(NULL) {}
			///����������� ������.
			///@param Sender - ��������� �� ������, ������� �������� �������� �������
			Event(RobotInternal *Sender) : m_SenderRobot(Sender) {}
		};
/**
*	@brief ��������� ������� OnMove ���� ����� �������
*/
		class MoveEvent : public Event 
		{
		private:
			///������ ���������� x (�� ����������� ������)
			int m_OldX;
			///������ ���������� y (�� ����������� ������)
			int m_OldY;
		public:
			///��������� ������ ���������� x
			int GetOldX() { return m_OldX; }
			///��������� ������ ��������� y
			int GetOldY() { return m_OldY; }
			///����������� ������
			/// @param Sender - ��������� �� ������, ������� �������� ���������� �������
			/// @param OldX - ������ x ����������
			/// @param OldY - ������ y ����������
			MoveEvent(RobotInternal *Sender,int OldX,int OldY) : Event(Sender),m_OldX(OldX),
			m_OldY(OldY) {}
		};

/**
*	@brief ��������� ������� OnTalk ���� ����� �������
*/
		class TalkEvent : public Event
		{
		public:
			TalkEvent(RobotInternal *Sender) : Event(Sender) {}
		};
/**
*	@brief ��������� ������� OnFire ���� ����� �������
*/
		class FireEvent : public Event
		{
		private:
			///��������� �� ������������� ������
			RobotInternal *m_KilledRobot;
		public:
			///�������� �������� �� �������� ��������. ���������� true, ���� 
			///� ���������� �������� ��� ��������� �����
			bool GetSuccess() { return m_KilledRobot!=NULL;}
			///����������� ������
			///@param Sender - �����, ������� �������� �������
			///@param KilledRobot - �������� �����, ���� �� ����� NULL, � ��������� ������, ������� ���� �� ������
			FireEvent(RobotInternal *Sender,RobotInternal *KilledRobot=NULL) 
				: Event(Sender),m_KilledRobot(KilledRobot) {}
		};

/**
*	@brief ��������� ������� OnNewRobotEvent ���� ����� �������
*/
		class NewRobotEvent: public Event
		{
		public:
			///����������� ������
			/// @param Sender - ����������� ������������ ����� � ����
			NewRobotEvent(RobotInternal *Sender) : Event(Sender) {}
		};

/**
*	@brief ����� ������������� �������� ������� � �������� "������-���-����������"
*/
		template <typename EARG>
		class EventDelegate :
			public RobotWar::MVC::ISubject<EARG>
		{
		public:
			
			~EventDelegate(void){m_ObserversStorage.clear();}
			///����������� ����������� �������
			/// @param observer - ����� ������� �����������, ����� �������� ��������� ��������� ��������� IObserver
			void Attach(IObserver<EARG> *observer) {m_ObserversStorage.push_back(observer);}
			///����� ����������� �� ��������� �������
			/// @param observer - ����� ������� �����������
			void Detach(IObserver<EARG> *observer) {m_ObserversStorage.remove(observer);}
			///��������� �������
			/// @param Sender - ��������� �������
			void Notify(EARG &Sender)
			{
				for(list<IObserver<EARG>*>::iterator i = m_ObserversStorage.begin();
					i != m_ObserversStorage.end();
					i++)
					(*i)->Update(Sender);
					;
			}

		private:
			///������ ������������, ���������� �������� �������
			list<IObserver<EARG>*> m_ObserversStorage;
		};
	}
}
