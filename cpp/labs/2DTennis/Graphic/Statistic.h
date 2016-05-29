#pragma once
#include "Sprite.h"
#include "GraphicEngine.h"

namespace Graphics
{

	class Statistic:
		public Sprite
	{
	private:
		ID3DXFont* T_font;
	public:
		virtual void Update(int dt);
		virtual void Draw();
		virtual void FreeResources();
		Statistic(GraphicEngine* engine, LPCSTR texture);
		~Statistic(void);
	};
}
