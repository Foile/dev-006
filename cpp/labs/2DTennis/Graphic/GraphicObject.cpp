#include "GraphicObject.h"
using namespace Graphics;

GraphicObject::GraphicObject(void)
{
	T_x = 0.0f;
	T_y = 0.0f;
	T_z = 0.0f;
	T_currentAngle = 0.0f;
}

GraphicObject::~GraphicObject(void)
{
}


void GraphicObject::SetX(float x)
{
	T_x = x;
}


void GraphicObject::SetY(float y)
{
	T_y = y;
}

void GraphicObject::SetZ(float z)
{
	T_z = z;
}


float GraphicObject::GetX()
{
	return T_x;
}

float GraphicObject::GetY()
{
	return T_y;
}

float GraphicObject::GetZ()
{
	return T_z;
}


float GraphicObject::GetAngle()
{
	return T_currentAngle;
}