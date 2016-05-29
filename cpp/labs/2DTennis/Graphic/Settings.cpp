#include "Settings.h"
#include "Controller.h"

using namespace Graphics;

Settings::Settings(GraphicEngine* engine, LPCSTR texture):
	Sprite(engine, texture)
{
	D3DXCreateFont(T_d3dDevice,36, 20, 50, 1, 0,0,0,5, 0,0,&T_font);
}

Settings::~Settings(void)
{
}

void Settings::Update(int dt)
{
}
void Settings::Draw()
{
	RECT rect1,rect2,rect3;
	rect1.top = 100;
	rect1.bottom = 150;
	rect1.left = 100;
	rect1.right = 600;
	rect2.top = 200;
	rect2.bottom = 250;
	rect2.left = 100;
	rect2.right = 500;
	rect3.top = 300;
	rect3.bottom = 350;
	rect3.left = 100;
	rect3.right = 500;
	D3DCOLOR color;
	memset(&color,255,sizeof(color));

	T_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	char* diff = new char[64];
	memset(diff,0,64);
	strcat(diff,"Diffictility - ");
	switch (Controller::GetDiff())
	{
		case 1: 
		{
			strcat(diff, "EASY");
			break;
		}
		case 2: 
		{
			strcat(diff, "MEDIUM");
			break;
		}
		case 3: 
		{
			strcat(diff, "HARD");
			break;
		}
	}

	T_font->DrawText(T_sprite, diff, -1, &rect1, DT_LEFT, color);
	memset(diff, 0,64);
	strcat(diff, "Field - ");
	switch (Controller::GetField())
	{
		case 1: 
		{
			strcat(diff, "Synthetic");
			break;
		}
		case 2: 
		{
			strcat(diff, "Grass");
			break;
		}
		case 3: 
		{
			strcat(diff, "Hard");
			break;
		}
	}

	T_font->DrawText(T_sprite, diff, -1, &rect2, DT_LEFT, color);
	T_font->DrawText(T_sprite, "Main Menu", -1, &rect3, DT_LEFT, color);
	T_sprite->End();
}

void Settings::FreeResources()
{
}
