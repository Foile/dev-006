#include "Controller.h"
#include "ObjectStorage.h"

using namespace Graphics;

PhysicEngine* Controller::T_engine = 0;
GraphicEngine* Controller::T_graphics = 0;
int Controller::T_direction = 0;
int Controller::T_motion = 0;
unsigned int Controller::T_force = 0;
unsigned int Controller::T_delta = 0;
bool Controller::started = true;
bool Controller::T_shoot = false;
bool Controller::T_computerShoot = false;
Player* Controller::T_player1 = 0;
Computer* Controller::T_player2 = 0;
Ball* Controller::T_ball = 0;
int Controller::T_diff = 1;
int Controller::T_field = 1;
int Controller::T_playerPoints = 0;
int Controller::T_playerGames = 0;
int Controller::T_compPoints = 0;
int Controller::T_compGames = 0;



Controller::Controller()
{
}

void Controller::SetEngine(PhysicEngine *engine)
{
	T_engine = engine;
	T_direction = 1;
	T_force = 0;

}

Controller::~Controller(void)
{
}



void Controller::SetGraphics(GraphicEngine *engine)
{
	T_graphics = engine;
}

GraphicEngine* Controller::GetGraphics()
{
	return T_graphics;
}

void Controller::incDelta()
{
	if (T_delta < 250)
		T_delta += 10;
}

void Controller::decDelta()
{
	if (T_delta > 0)
		T_delta -= 10;
}

unsigned int Controller::getDelta()
{
	return T_delta;
}

void Controller::setDelta(unsigned int delta)
{
	T_delta = delta;
}

void Controller::left()
{
	T_direction = -1;
}
void Controller::right()
{
	T_direction = 1;
}
void Controller::stop()
{
	T_direction = 0;
}

void Controller::stop2()
{
	T_motion = 0;
}

void Controller::up()
{
	T_motion = 1;
}

void Controller::down()
{
	T_motion = -1;
}

int Controller::getDirection()
{
	return T_direction;
}
int Controller::getMotion()
{
	return T_motion;
}

void Controller::shoot()
{
	T_shoot = !T_shoot;
}

void Controller::computerShoot()
{
	T_computerShoot = !T_computerShoot;
}


bool Controller::getShoot()
{
	return T_shoot;
}


bool Controller::getComputerShoot()
{
	return T_computerShoot;
}

void Controller::SetPlayer1(Player *player)
{
	T_player1 = player;
}

void Controller::SetPlayer2(Computer *player)
{
	T_player2 = player;
}

void Controller::SetBall(Ball* ball)
{
	T_ball = ball;
}

Player* Controller::GetPlayer1()
{
	return T_player1;
}

Computer* Controller::GetPlayer2()
{
	return T_player2;
}

Ball* Controller::GetBall()
{
	return T_ball;
}

void Controller::IncDiff()
{
	T_diff++;
	if (T_diff > 3)
		T_diff = 1;
}

int Controller::GetDiff()
{
	return T_diff;
}

void Controller::IncField()
{
	T_field++;
	if (T_field > 3)
		T_field = 1;
}

int Controller::GetField()
{
	return T_field;
}

void Controller::IncPlayerPoints()
{
	switch (T_playerPoints)
	{
		case 0:
			T_playerPoints = 15;
			break;
		case 15:
			T_playerPoints = 30;
			break;
		case 30:
			T_playerPoints = 40;
			break;
		case 40:
			T_playerPoints = 0;
			T_compPoints = 0;
			T_playerGames++;
			if (T_playerGames == 6)
			{
				MessageBox(0,"You are WIN!!!", "2D Tennis", MB_OK);
				ObjectStorage::Inst().SetCurrentScene(MAIN_MENU);
				T_playerPoints = 0;
				T_playerGames = 0;
				T_compPoints = 0;
				T_compGames = 0;
			}
			break;
	}
}

void Controller::IncCompPoints()
{
	switch (T_compPoints)
	{
		case 0:
			T_compPoints = 15;
			break;
		case 15:
			T_compPoints = 30;
			break;
		case 30:
			T_compPoints = 40;
			break;
		case 40:
			T_compPoints = 0;
			T_playerPoints = 0;
			T_compGames++;
			if (T_compGames == 6)
			{
				MessageBox(0,"You are LOOSE!", "2D Tennis", MB_OK);
				ObjectStorage::Inst().SetCurrentScene(MAIN_MENU);
				T_playerPoints = 0;
				T_playerGames = 0;
				T_compPoints = 0;
				T_compGames = 0;
			}
			break;
	}
}

int Controller::GetPlayerPoints()
{
	return T_playerPoints;
}

int Controller::GetPlayerGames()
{
	return T_playerGames;
}

int Controller::GetCompPoints()
{
	return T_compPoints;
}

int Controller::GetCompGames()
{
	return T_compGames;
}

void Controller::NewGame()
{
	T_playerGames = 0;
	T_playerPoints = 0;
	T_compPoints = 0;
	T_compGames = 0;
	T_player1->SetX(0.5f);
	T_player2->SetX(0.5f);
}