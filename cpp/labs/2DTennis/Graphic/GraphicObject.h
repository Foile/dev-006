#pragma once

namespace Graphics
{

	class GraphicObject
	{
	protected:
		float T_x;
		float T_y;
		float T_z;
		float T_rotationDeltaX;
		float T_rotationDeltaY;
		float T_rotationDeltaZ;
		float T_currentAngle;
		
	public:
		GraphicObject(void);
		virtual ~GraphicObject(void);
		virtual void Update(int dt) = 0;
		virtual void Draw() = 0;
		virtual void Rotate(float x, float y, float z, float degree) = 0;
		virtual void SetRotationPoint(float deltaX, float deltaY, float deltaZ) = 0;
		float GetX();
		float GetY();
		float GetZ();
		float GetAngle();
		virtual void SetX(float x);
		virtual void SetY(float y);
		virtual void SetZ(float z);
		
	};
}
