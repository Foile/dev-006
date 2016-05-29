#pragma once

//#include "IRobotOperation.h"

namespace RobotWar
{

class IRobotOperation;


/**
*	@brief	��������� IRobot ����������� ������� ������������, ������� ������ ���� ���������� �� ������� ������������ �����������, ����������� �� ���������� ������������
*/
class IRobot
{
public:

	
	/// ��������� ����� ������. ���������� ��� ������, ������������ �������������
	virtual char* getName(void) = 0;
	

	///����� ��������. ���������� ����� ���������, ����� ������ ����� �������� ��������� ������, ������������ ������ ����� ����������
	virtual void ReceiveMessage(char* RobotName, void* TalkData) = 0;

	///����� ���������� ������ ������. ���� ����� ���������� ��� �������� ��� ������ ���������� ������
	virtual void Execute(IRobotOperation *Engine)=0;
};

}