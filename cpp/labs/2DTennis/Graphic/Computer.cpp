#include "Computer.h"
#include "Controller.h"
#include "defines.h"

using namespace Graphics;

Computer::Computer(GraphicEngine* engine, LPCSTR texture):
	Sprite(engine, texture)
{
	T_frames = new IDirect3DTexture9*[3];
	D3DXCreateTextureFromFile(T_d3dDevice,"comp1.png",&(T_frames[0]));
	D3DXCreateTextureFromFile(T_d3dDevice,"comp2.png",&(T_frames[1]));
	D3DXCreateTextureFromFile(T_d3dDevice,"comp3.png",&(T_frames[2]));
	T_texture = T_frames[0];
	T_counter = 0;
	T_prevY = 0.0f;
}

Computer::~Computer(void)
{
	
}

void Computer::Update(int dt)
{
	Rotate(0,0,0, 0);	
	GraphicObject* obj = Controller::GetBall();
	if (fabs(obj->GetY() - T_y ) < SHOOT_RADIUS_Y && obj->GetY() <= T_prevY)
		Controller::computerShoot();
	T_prevY = obj->GetY();
	if ((obj->GetX() - T_x + CENTER_DISP_COMP) > SHOOT_RADIUS_X_COMP 
		&& T_x < OUT_LINE_TOP_RIGHT)
	{
		for (int i = 0; i < Controller::GetDiff();i++)
			T_x += COMPUTER_SPEED*(0.4f + 0.6*T_y);
		T_texture = T_frames[2];
		T_move = true;
	}
	else
		if ((obj->GetX() - T_x - CENTER_DISP_COMP) < -SHOOT_RADIUS_X_COMP 
			&& T_x > OUT_LINE_TOP_LEFT)
	{
		for (int i = 0; i < Controller::GetDiff();i++)
			T_x -= COMPUTER_SPEED*(0.4f + 0.6*T_y);
		T_texture = T_frames[1];
		T_move = true;
	}
	else
	if (!T_move)
	{
		T_texture = T_frames[0];
	}
	

	if (Controller::getShoot())
	{
		T_counter = 10;
		T_move = false;
	}

	if (T_counter)
	{
		T_texture = T_frames[0];
		T_counter--;
	}
	
}

void Computer::FreeResources()
{
	
}

