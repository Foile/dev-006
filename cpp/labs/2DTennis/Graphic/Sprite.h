#pragma once
#include "DirectXObject.h"
#include "DirectXEngine.h"
#include <d3dx9.h>


namespace Graphics
{
	class Sprite :
		public DirectXObject
	{
	protected:
		IDirect3DTexture9* T_texture;
		ID3DXSprite* T_sprite;
		float T_width;
		float T_height;
	public:
		Sprite(GraphicEngine* engine, LPCSTR texture);
		~Sprite(void);
		virtual void Update(int dt) = 0;
		virtual void Draw();
		virtual void Rotate(float x, float y, float z, float degree);
		virtual void FreeResources() = 0;
		virtual void SetX(float x);
		virtual void SetY(float y); 
		void SetWidth(float width);
		void SetHeight(float height);
		float GetWidth();
		float GetHeight();
	};
}
