#pragma once
#include "Sprite.h"
#include "GraphicEngine.h"


namespace Graphics
{
	class Ball :
		public Sprite
	{
	private:
		float T_vx;
		float T_vy;
		float T_vz;
	public:
		Ball(GraphicEngine* engine, LPCSTR texture);
		~Ball(void);
		virtual void Update(int dt);
		virtual void FreeResources();
	};
}