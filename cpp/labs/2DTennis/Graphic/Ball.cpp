#include "Ball.h"
#include "Controller.h"
#include "defines.h"

using namespace Graphics;

Ball::Ball(GraphicEngine* engine, LPCSTR texture):
	Sprite(engine, texture)
{
	T_vx = 0.0f;
	T_vy = 0.0f;
	T_vz = 0;
}

Ball::~Ball(void)
{
}


void Ball::Update(int dt)
{
	if (Controller::getShoot())
	{
		GraphicObject* player = Controller::GetPlayer1();
		if (fabs(player->GetY() - T_y) < SHOOT_RADIUS_Y && T_vy <= 0.0f &&
			fabs(player->GetX() - T_x + CENTER_DISP_PLAYER) < SHOOT_RADIUS_X_PLAYER)
		{
			T_vy = BALL_SPEED;
			T_vx = (T_y - player->GetY())/5.0f;
		}
	}
	if (Controller::getComputerShoot())
	{
		GraphicObject* player = Controller::GetPlayer2();
		if (fabs(player->GetY() - T_y) < SHOOT_RADIUS_Y && T_vy > 0.0f &&
			fabs(player->GetX() - T_x + CENTER_DISP_COMP) < SHOOT_RADIUS_X_COMP)
		{
			T_vy = -T_vy;
			T_vx = ((float)((GetTickCount())%3) - 1)*0.01f;
		}
	}

	T_x -= T_vx;

	if (T_y < -0.1f || T_y > 1.0f)
	{
		if (T_y > 1.0f)
			if (T_x > OUT_LINE_BOTTOM_LEFT && T_x < OUT_LINE_BOTTOM_RIGHT)
				Controller::IncCompPoints();
			else
				Controller::IncPlayerPoints();
		if (T_y < 0.0f)
			if (T_x > OUT_LINE_TOP_LEFT && T_x < OUT_LINE_TOP_RIGHT)
				Controller::IncPlayerPoints();
			else
				Controller::IncCompPoints();
		T_y = 0.6f;
		T_x = 0.5f;
		T_vx = 0.0f;
		T_vy = 0.00f;
		T_vz = 0;
	}
	T_y -= T_vy;
	Rotate(0,0,0,0);
}

void Ball::FreeResources()
{
}
