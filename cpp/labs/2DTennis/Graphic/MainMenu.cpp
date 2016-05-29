#include "MainMenu.h"
using namespace Graphics;


MainMenu::MainMenu(GraphicEngine* engine, LPCSTR texture):
	Sprite(engine,texture)
{
	D3DXCreateFont(T_d3dDevice,36, 20, 50, 1, 0,0,0,5, 0,0,&T_font);
}

MainMenu::~MainMenu(void)
{

}

void MainMenu::Update(int dt)
{
}

void MainMenu::Draw()
{
	RECT rect1,rect2,rect3;
	rect1.top = 100;
	rect1.bottom = 150;
	rect1.left = 100;
	rect1.right = 500;
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

	
	T_font->DrawText(T_sprite, "New game", -1, &rect1, DT_LEFT, color);
	T_font->DrawText(T_sprite, "Settings", -1, &rect2, DT_LEFT, color);
	T_font->DrawText(T_sprite, "Exit", -1, &rect3, DT_LEFT, color);
	T_sprite->End();


}

void MainMenu::FreeResources()
{
}
