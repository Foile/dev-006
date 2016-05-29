#include "SampleView.h"



LRESULT CALLBACK HandleEvent(HWND hWnd,UINT msg,WPARAM wParam, LPARAM lParam);

SampleView::SampleView(HWND hWnd) : m_hWnd(hWnd)
{
	m_HDC = GetDC(hWnd);
}

SampleView::~SampleView(void)
{
	ReleaseDC(m_hWnd,m_HDC);
}

void SampleView::Update(MoveEvent &e)
{
 	int x = e.GetOldX();
	int y = e.GetOldY();
	RECT rOld = {x,y,x+40,y+40};
	FillRect(m_HDC,&rOld,(HBRUSH)GetStockObject(WHITE_BRUSH));

	x = e.GetSender()->getX();
	y = e.GetSender()->getY();
	RECT rNew = {x,y,x+40,y+40};
	FillRect(m_HDC,&rNew,(HBRUSH)GetStockObject(GRAY_BRUSH));
}
void SampleView::Update(TalkEvent &e)
{
	//TO DO
}

void SampleView::Update(NewRobotEvent &e)
{

	int x = e.GetSender()->getX();
	int y = e.GetSender()->getY();
	RECT r = {x,y,x+40,y+40};
	FillRect(m_HDC,&r,(HBRUSH)GetStockObject(GRAY_BRUSH));
}
