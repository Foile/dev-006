#pragma once
#include "Sprite.h"
#include "GraphicEngine.h"

namespace Graphics
{

	class Settings:
		public Sprite
	{
	private:
		ID3DXFont* T_font;
	public:
		Settings(GraphicEngine* engine, LPCSTR texture);
		~Settings(void);
		virtual void Update(int dt);
		virtual void Draw();
		virtual void FreeResources();
	};
}