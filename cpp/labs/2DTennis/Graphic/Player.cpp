#include "Player.h"
#include "Controller.h"
#include "defines.h"

using namespace Graphics;

Player::Player(GraphicEngine* engine, LPCSTR texture):
	Sprite(engine, texture)
{
	T_frames = new IDirect3DTexture9*[3];
	D3DXCreateTextureFromFile(T_d3dDevice,"pl1.png",&(T_frames[0]));
	D3DXCreateTextureFromFile(T_d3dDevice,"pl2.png",&(T_frames[1]));
	D3DXCreateTextureFromFile(T_d3dDevice,"pl3.png",&(T_frames[2]));
	T_texture = T_frames[0];
	T_counter = 0;
}

Player::~Player(void)
{
}

void Player::Update(int dt)
{
	Rotate(0,0,0, 0);
	if ((Controller::getDirection() == 1) && (T_x <= 1.0f))
	{
		T_x += PLAYER_SPEED_X*(0.4f + 0.6*T_y);
		T_texture = T_frames[2];
	}
	else
	if ((Controller::getDirection() == -1) &&(T_x >= 0.0f))
	{
		T_x -= PLAYER_SPEED_X*(0.4f + 0.6*T_y);
		T_texture = T_frames[1];
	}
	else
		T_texture = T_frames[0];

	if ((Controller::getMotion() == 1) && (T_y >= 0.2f))
		T_y -= PLAYER_SPEED_Y;

	if ((Controller::getMotion() == -1) && (T_y <= 0.8f))
		T_y += PLAYER_SPEED_Y;

	if (Controller::getShoot())
		T_counter = 10;

	if (T_counter)
	{
		T_texture = T_frames[0];
		T_counter--;
	}
	
}

void Player::FreeResources()
{
	
}
