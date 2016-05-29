#pragma once
#include "Sprite.h"
#include "GraphicEngine.h"

namespace Graphics
{

	class Computer:
		public Sprite
	{
		IDirect3DTexture9** T_frames;
		char T_counter;
		bool T_move;
		float T_prevY;
	public:
		Computer(GraphicEngine* engine, LPCSTR texture);
		~Computer(void);
		virtual void Update(int dt);
		virtual void FreeResources();
	};
}