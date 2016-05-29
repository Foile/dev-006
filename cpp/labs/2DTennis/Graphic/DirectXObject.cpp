#include "DirectXObject.h"
#include <D3dx9.h>
#include <math.h>

using namespace Graphics;

DirectXObject::DirectXObject(GraphicEngine * d3dDevice)
{
	T_view = 0.0f;
	T_x = 0.0f;
	T_y = 0.0f;
	T_z = 0.0f;
	T_d3dDevice = ((DirectXEngine*)d3dDevice)->GetDevice();
}

DirectXObject::~DirectXObject(void)
{
	
	
}


void DirectXObject::Rotate(float x, float y, float z, float degree)
{
	// For rotation
	D3DXMATRIXA16 worldX;
	D3DXMATRIXA16 worldY;
	D3DXMATRIXA16 worldZ;
	D3DXMATRIXA16 world;
	// Translation in 0
	D3DXMATRIXA16 translation1;
	// Back up translation
	D3DXMATRIXA16 translation2;
	D3DXMatrixRotationX(&world ,0.0f);
	//D3DXMatrixMultiply(&world, &world, &world);
	if (abs(x) > 0.01f)
	{
		D3DXMatrixRotationX(&worldX, (T_currentAngle)*(2*D3DX_PI/360) + x*degree*((2*D3DX_PI)/360));
		D3DXMatrixMultiply(&world, &world, &worldX);
	}
	if (abs(y) > 0.01f)
	{
		D3DXMatrixRotationY(&worldY, (T_currentAngle)*(2*D3DX_PI/360) + y*degree*((2*D3DX_PI)/360));
		D3DXMatrixMultiply(&world, &world, &worldY);
	}
	if (abs(z) > 0.01f)
	{
		D3DXMatrixRotationZ(&worldZ, (T_currentAngle)*(2*D3DX_PI/360) + z*degree*((2*D3DX_PI)/360));
		D3DXMatrixMultiply(&world, &world, &worldZ);
	}
	
	D3DXMatrixTranslation(&translation1,
		-T_x - T_rotationDeltaX, 
		-T_y - T_rotationDeltaY,
		-T_z - T_rotationDeltaZ);
	D3DXMatrixMultiply(&world, &translation1, &world);
	D3DXMatrixTranslation(&translation2,
		T_x + T_rotationDeltaX, 
		T_y + T_rotationDeltaY, 
		T_z + T_rotationDeltaZ);
	D3DXMatrixMultiply(&world, &world, &translation2);
	T_d3dDevice->SetTransform(D3DTS_WORLD, &world);

	T_currentAngle += degree;
	
}

void DirectXObject::SetRotationPoint(float deltaX, float deltaY, float deltaZ)
{
	T_rotationDeltaX =  deltaX;
	T_rotationDeltaY =  deltaY;
	T_rotationDeltaZ =  deltaZ;
}

void DirectXObject::SetX(float x)
{
	D3DXMATRIXA16 translation1;
	if (!(T_matrixDeterm))
	{
		T_matrix = *(new D3DXMATRIXA16());
		D3DXMatrixRotationX(&T_matrix ,0.0f);
		T_matrixDeterm = true;
	}

	D3DXMatrixTranslation(&translation1,
		x - T_x, 
		0.0f,
		0.0f);
	D3DXMatrixMultiply(&T_matrix, &translation1, &T_matrix );
	T_d3dDevice->SetTransform(D3DTS_WORLD, &T_matrix);
	T_x = x;
}

void DirectXObject::SetY(float y)
{
	D3DXMATRIXA16 translation1;
	if (!(T_matrixDeterm))
	{
		T_matrix = *(new D3DXMATRIXA16());
		D3DXMatrixRotationX(&T_matrix ,0.0f);
		T_matrixDeterm = true;
	}


	D3DXMatrixTranslation(&translation1,
		0.0f, 
		y - T_y,
		0.0f);
	D3DXMatrixMultiply(&T_matrix,&translation1,  &T_matrix );
	T_d3dDevice->SetTransform(D3DTS_WORLD, &T_matrix);
	T_y = y;

}