#pragma once
#include "DirectXObject.h"
#include "GraphicEngine.h"

namespace Graphics
{
	class Field :
		public DirectXObject
	{
	private:
		IDirect3DVertexBuffer9* T_lines;
		IDirect3DVertexBuffer9* T_field2;
		IDirect3DVertexBuffer9* T_field3;
		IDirect3DVertexBuffer9* T_bg;
	public:
		Field(GraphicEngine* engine);
		~Field(void);
		virtual void Update(int dt);
		virtual void Draw();
		virtual void FreeResources();
		virtual void SetX(float x) {};
		virtual void SetY(float y) {};
	};
}
