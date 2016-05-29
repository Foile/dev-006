#include "Sprite.h"
#include "defines.h"

using namespace Graphics;

Sprite::Sprite(GraphicEngine* engine, LPCSTR texture): DirectXObject(engine)
{
	D3DXCreateTextureFromFile(T_d3dDevice, texture, &T_texture);
	D3DXCreateSprite(T_d3dDevice, &T_sprite);
	
}

Sprite::~Sprite(void)
{
}


void Sprite::Draw()
{
	T_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 center = D3DXVECTOR3((float)(T_width/2), 
		(float)(T_height/2), T_z);
	D3DXVECTOR3 position = D3DXVECTOR3(T_x*SCREEN_WIDTH, 
		T_y*SCREEN_HEIGHT, 0);
	T_sprite->Draw(T_texture, 0, 0, &position, 0xffffffff);

	T_sprite->End();
}


void Sprite::Rotate(float x, float y, float z, float degree)
{
	D3DXMATRIX matrix;

	D3DXVECTOR2 scalingCenter = D3DXVECTOR2(T_x*SCREEN_WIDTH, T_y*SCREEN_HEIGHT);
	D3DXVECTOR2 scaling = D3DXVECTOR2(0.4f + 0.6f*T_y,0.4f + 0.6f*T_y);
	D3DXVECTOR2 rotationCenter = D3DXVECTOR2(T_x*(float)SCREEN_WIDTH + T_rotationDeltaX*(float)T_width,
							T_y*(float)SCREEN_HEIGHT + T_rotationDeltaY*(float)T_height);
	D3DXVECTOR2 translation = D3DXVECTOR2(T_rotationDeltaX, T_rotationDeltaY);

	D3DXMatrixTransformation2D(&matrix, &scalingCenter, 1.0f, 
		&scaling, &rotationCenter,D3DXToRadian(degree), 0);

	T_sprite->SetTransform(&matrix);
	
}


void Sprite::SetX(float x)
{
	T_x = x;
}

void Sprite::SetY(float y)
{
	T_y = y;
}

void Sprite::SetWidth(float width)
{
	T_width = width;
}

void Sprite::SetHeight(float height)
{
	T_height = height;
}

float Sprite::GetWidth()
{
	return T_width;
}

float Sprite::GetHeight()
{
	return T_height;
}