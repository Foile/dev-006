#pragma once
#include "IRobot.h"

namespace RobotWar
{
/**
	@brief ���������, �������� ���������� ������ ��� ����� IRobotOperation::LookAround
*/
	struct PT 
	{
		int x,y;
	};
/**
	@brief ��������� ���� ������� ���������
*/
class IRobotOperation
{
public:

	
	/// ���������� ������ �� ��������� ���������� ��������� (�� ����� 3)
	/// @param Sender - �����, ������� ���������� � ����. ������� ��������� this
	/// @param x - ���������� �� x (0<=x<3)
	/// @param y - ���������� �� y (0<=y<3)
	virtual void Move(IRobot *Sender,int x, int y) = 0;

	/// ��������� ������ ���������� ������� �� ��������� ���������� (�� ����� 3)
	/// @param Sender - �����, ������� ���������� � ����. ������� ��������� this
	/// @param x - ���������� �� x (0<=x<3)
	/// @param y - ���������� �� y (0<=y<3)
	virtual void Fire(IRobot *Sender,int x, int y) = 0;

    ///��������� ������ �������� ���������� � ������������� ������ ������� � ������� depth
	/// @param Sender - �����, ������� ���������� � ����. ������� ��������� this
	/// @param depth - ������� ��������� (0<=depth<3)
	/// @param CountPoints - ���������� ��������� � ������ ��� ���������� ������� ���������
	/// @param pPoints - ������ �������� PT ��� ���������� ���������, � ������� ���� �������
	virtual void LookAround(IRobot *Sender,int depth,int CountPoints,PT *pPoints) = 0;

	///��������� ������ ��������� ��������� ������� ������
	/// @param Sender - �����, ������� ���������� � ����. ������� ��������� this
	/// @param RobotName - ������, ���������� ��� ������, �������� ������������ ���������
	/// @param TalkData - �����, ���������� ������������ ������� ������ ������
	virtual void SendMsg(IRobot *Sender, char *RobotName, void *TalkData) = 0;
};

}