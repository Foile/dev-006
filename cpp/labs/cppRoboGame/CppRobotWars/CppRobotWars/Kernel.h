#pragma once
#include "irobotoperation.h"
#include "RobotInternal.h"
#include "thread.h"
#include "MyException.h"
#include "TalkThread.h"
#include "EventDelegate.h"
#include <map>
#include <vector>

using namespace std;
using namespace RobotWar::MVC;

namespace RobotWar
{
	namespace Kernel
	{
/**
*	@brief ����������, ������� ������������� ��� ������������ ����������, ���������� 
*	��� ������ ������� ���������� IRobotOperation
*/
	class ParametersContractError : public RobotWarException 
	{
	};
/**
*	@brief ����������, ������� ������������� ��� ������������� ����������� ������
    � ��������� ����������, ��� ��� � ���� ����������� ��������� �����-�� ������
*/
	class NoValidMove : public RobotWarException
	{
	};
/**
	@brief �����, ����������� ���� ������� ���������, ���������� � ��������� ������
*/
	class Kernel :
		public IRobotOperation, 
		public RobotWar::Infrastructure::Thread
	{
	private:
		///������, ������� ���������� � ����
		map<IRobot*,RobotInternal*> m_GameMembersStorage;
		Kernel(void);
		///��������� �� ����. ������������ � �������� Singleton
		static Kernel *m_Kernel;
	public:	
		///������������� ���������-������� �� ������� OnMove. ������ ������� ���������� ��� 
		///����������� ������ ������
		EventDelegate<MoveEvent> OnMove;
		///������������� ���������-������� �� ������� OnMove. ������ ������� ���������� ��� 
		///��� �������� ������ ������
		EventDelegate<FireEvent> OnFire;
		///������������� ���������-������� �� ������� OnFire. ������ ������� ���������� ��� 
		///�������� ����� �������� ���������
		EventDelegate<TalkEvent> OnTalk;
		///������������� ���������-������� �� ������� OnTalk. ������ ������� ���������� ��� 
		///���������� ������ ������ � ����
		EventDelegate<NewRobotEvent> OnNewRobot;

		virtual ~Kernel(void);
		/// ���������� ������ �� ��������� ���������� ��������� (�� ����� 3)
		/// @param Sender - �����, ������� ���������� � ����
		/// @param x - ���������� �� x (0<=x<3)
		/// @param y - ���������� �� y (0<=y<3)
		void Move(IRobot *Sender,int x, int y);
		/// ��������� ������ ���������� ������� �� ��������� ���������� (�� ����� 3)
		/// @param Sender - �����, ������� ���������� � ����
		/// @param x - ���������� �� x (0<=x<3)
		/// @param y - ���������� �� y (0<=y<3)
		void Fire(IRobot *Sender,int x, int y);
		///��������� ������ �������� ���������� � ������������� ������ ������� � ������� depth
		/// @param Sender - �����, ������� ���������� � ����. ������� ��������� this
		/// @param depth - ������� ��������� (0<=depth<3)
		/// @param CountPoints - ���������� ��������� � ������ ��� ���������� ������� ���������
		/// @param pPoints - ������ �������� PT ��� ���������� ���������, � ������� ���� �������
		void LookAround(IRobot *Sender,int depth, int CountPoints, RobotWar::PT* pPoints);
		///��������� ������ ��������� ��������� ������� ������
		/// @param Sender - �����, ������� ���������� � ����
		/// @param RobotName - ������, ���������� ��� ������, �������� ������������ ���������
		/// @param TalkData - �����, ���������� ������������ ������� ������ ������
		void SendMsg(IRobot *Sender,char *RobotName, void *TalkData);
		/// ����� ���������� ������ �����
		void Execute(void);
		///������ ������ ���� (������ ����)
		void Start(void);
		///������� ������ ���� (������� ����)
		void Stop(void);
		///������������ ������
		void Suspend(void);
		///������������� ������
		void Resume(void);

		///��������� ������ ��� ��������� ����
		/// @param Robot - ��������� �� ������������ ������
		void AddRobot(RobotInternal* Robot);
	    

		static Kernel* CreateKernel(void);
	private:
		///������ ����������� ���������, ������������ ����� ��������
		vector<TalkThread*> m_TalkThreadStorage;
	};
	}	
}