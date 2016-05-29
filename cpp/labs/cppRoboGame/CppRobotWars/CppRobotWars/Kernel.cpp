#include "Kernel.h"
#include "TalkThread.h"

using namespace RobotWar::Kernel;

Kernel *Kernel::m_Kernel = NULL;

Kernel::Kernel(void)
{
 srand(1000);
}

Kernel::~Kernel(void)
{
	for(vector<TalkThread*>::iterator i = m_TalkThreadStorage.begin();
		i != m_TalkThreadStorage.end(); i++)
		delete *i;
}

void RobotWar::Kernel::Kernel::Move(IRobot *Sender,int x, int y)
{
	//проверяем допустимые параметры для перемещения
	if( x < -3 || x > 3 || y <-3 || y > 3) throw ParametersContractError();
    map<IRobot*,RobotInternal*>::iterator	c =  m_GameMembersStorage.find(Sender);
    if(c == m_GameMembersStorage.end())
	  throw ParametersContractError();

	RobotInternal *CurrentRobot = c->second;
	int NeedX = CurrentRobot->getX()+x;
    int NeedY = CurrentRobot->getY()+y;
	
	//проверяем, можем ли мы пойти по указанным координатам
	for( map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		 i != m_GameMembersStorage.end(); i++)
		 if(i->first != Sender && NeedX == i->second->getX() && NeedY == i->second->getY())
			throw NoValidMove();
	
	MoveEvent e(CurrentRobot,CurrentRobot->getX(),CurrentRobot->getY());
	CurrentRobot->SetX(NeedX);
	CurrentRobot->SetY(NeedY);
	Sleep(20);
	OnMove.Notify(e);
}

void RobotWar::Kernel::Kernel::Fire(IRobot *Sender,int x, int y)
{
	if( x < -3 || x > 3 || y <-3 || y > 3) throw ParametersContractError();
    map<IRobot*,RobotInternal*>::iterator	c =  m_GameMembersStorage.find(Sender);
    if(c == m_GameMembersStorage.end())
	  throw ParametersContractError();

	for( map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		 i != m_GameMembersStorage.end(); i++)
		 if(x == i->second->getX() && y == i->second->getY())
		 {
			 i->second->DecreaseHealth(25);
			 if(i->second->getHealt() == 0)
				 i->second->Stop();
			 FireEvent e(c->second,i->second);
			 OnFire.Notify(e);
		 }
		 else
		 {
			 FireEvent e(c->second);
			 OnFire.Notify(e);
		 }
}

void RobotWar::Kernel::Kernel::LookAround(IRobot *Sender,int depth, int CountPoints, RobotWar::PT* pPoints)
{
	if(depth > 3 || depth < 0 ) 
		throw ParametersContractError();
	//ищем робота, который сканирует окрестности
	map<IRobot*,RobotInternal*>::iterator	c =  m_GameMembersStorage.find(Sender);
    if(c == m_GameMembersStorage.end())
	  throw ParametersContractError();
	int Count=0;
	for(map<IRobot*,RobotInternal*>::iterator i= m_GameMembersStorage.begin();
		i != m_GameMembersStorage.end();i++)
	{

	}
}

void RobotWar::Kernel::Kernel::AddRobot(RobotInternal* Robot)
{
	if(!Robot) throw ParametersContractError();
	//запоминаем робота
	m_GameMembersStorage[Robot->QueryIRobot()] = Robot;

	//ставим робота в случайные координаты
	int x = (double)rand() / (RAND_MAX + 1) * (400 - 0)
            + 0;
	int y = (double)rand() / (RAND_MAX + 1) * (400 - 0)
            + 0;
	Robot->SetX(x);
	Robot->SetY(y);
	NewRobotEvent e(Robot);
	OnNewRobot.Notify(e);
}


void RobotWar::Kernel::Kernel::Execute(void)
{
	while(1) Sleep(20);//вот здесь по идее, что-то надо делать...
}

void RobotWar::Kernel::Kernel::Start(void)
{
	//необходимо запустить всех роботов в хранилище
	for( map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		 i != m_GameMembersStorage.end(); i++)
	 i->second->Start();
     		 
}

void RobotWar::Kernel::Kernel::Stop(void)
{
	//необходимо остановить всех роботов в хранилище
	for( map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		 i != m_GameMembersStorage.end(); i++)
	 i->second->Stop();
}

void RobotWar::Kernel::Kernel::Suspend(void)
{
	for( map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		 i != m_GameMembersStorage.end(); i++)
		 i->second->Suspend();
}

void RobotWar::Kernel::Kernel::Resume(void)
{
	for( map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		 i != m_GameMembersStorage.end(); i++)
		 i->second->Resume();
}

void RobotWar::Kernel::Kernel::SendMsg(IRobot *Sender,char* RobotName, void * TalkData)
{
	if(!Sender || !RobotName || !TalkData) throw ParametersContractError();
	for(map<IRobot*,RobotInternal*>::iterator i = m_GameMembersStorage.begin();
		i != m_GameMembersStorage.end(); i++)
		if(strcmp(RobotName,i->first->getName()) == 0)
		{
          TalkThread *thread = new TalkThread(i->first,RobotName,TalkData);
		  m_TalkThreadStorage.push_back(thread);
		  thread->Start();
		}
}

Kernel* RobotWar::Kernel::Kernel::CreateKernel(void)
{
	if(!m_Kernel)
	 m_Kernel = new Kernel;
	return m_Kernel;
}
