#pragma once
#include "IRobot.h"
#include "Thread.h"

using namespace RobotWar::Infrastructure;


namespace RobotWar
{
/**
	@brief �����, ����������� ������� ������� �����, �������������� � DLL. 
	���� ����� ��������� ��� �������� ������ ��� ���������� ������, � ����� 
	��� �������� ��� ������������� ������, ����� ��� ���������� � ��������
*/
class RobotInternal :
	public Thread
{
private:
	///��������� �� ������ ������, ����� �������� ���������� �� ������� DLL
	IRobot *m_pGamerRobot;
	///��������� �� ��������� ����
	IRobotOperation *m_Kernel;
public:
	///����������� ������
	/// @param Robot - ��������� �� ������ ������, ����� �������� ���������� �� ������� DLL
	/// @param Kernel - ��������� �� ����
	RobotInternal(IRobot *Robot,IRobotOperation *Kernel);
	///����������
	~RobotInternal(void);
	///���������� ��� ������, �������� ������������� ������ ������
	char* getName(void);
	///������������ ����� ���������, ������� ���������� ������ ������ (depricate)
	void ReceiveMessage(char* RobotName, void* TalkData);
	///�������� ����� ����
	void Execute(IRobotOperation*);
protected:
	/// �������� ������
	int m_Healt;
	/// ���������� x ������
	int m_X;
	///���������� y ������
	int m_Y;
public:

	///���������� �������� ������ � ��������� �� 0 �� 100
	int getHealt(void)
	{
		return m_Healt;
	}
	///���������� ���������� x ������
	int getX(void)
	{
		return m_X;
	}
	///���������� ���������� y ������

	int getY(void)
	{
		return m_Y;
	}

	///��������� �����. ���������� ��������� �� ������, ������� ���������� �� ������� DLL
	IRobot* QueryIRobot(void)
	{
		return m_pGamerRobot;
	}

	///����� ���������� ������ ������
	void Execute() 
	{
		m_pGamerRobot->Execute(m_Kernel);
	}	

	///��������� ���������� x ������
	void SetX(int x)
	{
		m_X = x;
	}
	///��������� ���������� y ������
	void SetY(int y)
	{
		m_Y = y;
	}

	///���������� �������� ������
	/// @param value - ��������, �� ������� ����������� ��������
	void DecreaseHealth(int value)
	{
		m_Healt -= value;
	}

};

}