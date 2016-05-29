#include "Statistic.h"
#include "Controller.h"


using namespace Graphics;

Statistic::Statistic(GraphicEngine* engine, LPCSTR texture):
	Sprite(engine, texture)
{
	D3DXCreateFont(T_d3dDevice,12, 10, 50, 1, 0,0,0,5, 0,0,&T_font);
}

Statistic::~Statistic(void)
{

}

void Statistic::Update(int dt)
{
}


void Statistic::Draw()
{
	RECT rect1,rect2;
	rect1.top = 5;
	rect1.bottom = 55;
	rect1.left = 600;
	rect1.right = 800;
	rect2.top = 55;
	rect2.bottom = 105;
	rect2.left = 600;
	rect2.right = 800;
	D3DCOLOR color;
	memset(&color,255,sizeof(color));

	T_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	char* text = new char[64];
	memset(text,0,64);
	strcat(text,"Player  : ");
	char* number = new char[10];
	memset(number,0,10);
	sprintf(number,"%d | %d", Controller::GetPlayerPoints(), Controller::GetPlayerGames());
	strcat(text, number);
	T_font->DrawText(T_sprite, text, -1, &rect1, DT_LEFT, color);
	memset(text, 0,64);
	memset(number,0,10);
	strcat(text, "Computer: ");
	sprintf(number,"%d | %d", Controller::GetCompPoints(), Controller::GetCompGames());
	strcat(text, number);
	T_font->DrawText(T_sprite, text, -1, &rect2, DT_LEFT, color);
	T_sprite->End();
}

void Statistic::FreeResources()
{
}


