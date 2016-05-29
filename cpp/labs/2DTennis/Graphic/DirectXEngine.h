#pragma once
#include "GraphicEngine.h"
#include <windows.h>
#include <d3dx9.h>


struct CUSTOMVERTEX
{
    FLOAT x, y, z; 
    DWORD color;        
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)


namespace Graphics
{

	class DirectXEngine :
		public GraphicEngine
	{
	private:
		IDirect3D9* T_device;
		IDirect3DDevice9 * T_d3dDevice;
	public:
		DirectXEngine(HWND wnd);
		~DirectXEngine(void);
		virtual void Init();
		virtual void Redraw();
		IDirect3DDevice9* GetDevice();
	};
}