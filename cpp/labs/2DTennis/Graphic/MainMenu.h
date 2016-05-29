#pragma once
#include "Sprite.h"
#include "GraphicEngine.h"

namespace Graphics
{

	class MainMenu :
		public Sprite
	{
	private:
		ID3DXFont* T_font;
	public:
		MainMenu(GraphicEngine* engine, LPCSTR texture);
		~MainMenu(void);
		virtual void Update(int dt);
		virtual void Draw();
		virtual void FreeResources();
	};

}