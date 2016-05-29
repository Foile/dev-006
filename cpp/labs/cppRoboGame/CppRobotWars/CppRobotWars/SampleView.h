#pragma once
#include "imvc.h"
#include "EventDelegate.h"
#include <windows.h>

using namespace RobotWar::MVC;
/**
*	@brief ������ ���� ��� ����� �������
*	
* ������ ����� ��������� ��������� ������� �� ������ (����� Kernel)
* ��� ��������� ����������� ��������� ������� �� ���� ���������� �����������
* ��������� ��������� IObserver<T>, ��� T ����� �������������� �� ������ Event 
* � ���������� ���������, ��������� � ��������
*/
class SampleView :
	public IObserver<MoveEvent>,
	public IObserver<TalkEvent>,
	public IObserver<NewRobotEvent>
{
private:
	///�������� ����
	HDC m_HDC;
	///���������� ����
	HWND m_hWnd;
public:
	/**
	 �����������
	 @param hWnd - ���������� ����, ���������������� ���� � �������� ������-���-����������
	*/
	SampleView(HWND hWnd);
	///����������
	~SampleView(void);
	/**
	���������� �������  OnMove �� ���� ����
	@param e - �������� ������� OnMove
	*/
	void Update(MoveEvent &e);
	/**
	���������� �������  OnTalk �� ���� ����
	@param e - �������� ������� OnTalk
	*/
	void Update(TalkEvent &e);
	/**
	���������� �������  OnNewRobot �� ���� ����
	@param e - �������� ������� TalkEvent
	*/
	void Update(NewRobotEvent &e);
};
