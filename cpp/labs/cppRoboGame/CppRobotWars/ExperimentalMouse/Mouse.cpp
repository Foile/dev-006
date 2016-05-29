#include "Mouse.h"
#include "irobotoperation.h"
#include <string.h>

Mouse::Mouse(void) : m_TalkData(NULL),m_Direction(right)
{
}

Mouse::~Mouse(void)
{
	if(m_TalkData) delete m_TalkData;
}

char* Mouse::getName(void)
{
	return "ExperimentalMouse";
}
void Mouse::ReceiveMessage(char* RobotName, void* TalkData)
{
	if(m_TalkData)  
		delete m_TalkData;
	m_TalkData = new char [strlen((char*)TalkData)+1];
	strcpy(m_TalkData,(char*)TalkData);
	if(strcmp(m_TalkData,"left") == 0) 
		m_Direction = left;
	else
		if(strcmp(m_TalkData,"right") == 0) 
			m_Direction = right;
		else if(strcmp(m_TalkData,"top") == 0) 
			m_Direction = top;
		else if(strcmp(m_TalkData,"bottom") == 0) 
			m_Direction = bottom;
}
void Mouse::Execute(IRobotOperation *Engine)
{
 int x=0,y=0;
 while(1)
 {
	switch(m_Direction)
	{
	case left: 
		x = -1;y=0;break;
	case right:
		x = 1;y=0;break;
	case top:
		x=0;y=-1;break;
	case bottom:
		x=0;y=1;break;
	}
	Engine->Move(this,x,y);
 }
}