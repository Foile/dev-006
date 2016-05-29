#pragma once
#include "Sprite.h"
#include "GraphicEngine.h"

namespace Graphics
{
	class Player :
		public Sprite
	{
	private:
		IDirect3DTexture9** T_frames;
		char T_counter;
	public:
		Player(GraphicEngine* engine, LPCSTR texture);
		~Player(void);
		virtual void Update(int dt);
		virtual void FreeResources();
	};
}