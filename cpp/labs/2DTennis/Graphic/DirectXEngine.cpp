#include "DirectXEngine.h"
#include "ObjectStorage.h"
#include <vector>

using namespace std;
using namespace Graphics;

DirectXEngine::DirectXEngine(HWND wnd):
	GraphicEngine(wnd)
{
}

DirectXEngine::~DirectXEngine(void)
{
	if (T_d3dDevice)
		T_d3dDevice->Release();
	T_d3dDevice = 0;
	if (T_device)
		T_device->Release();
	T_device = 0;
}


void DirectXEngine::Init()
{
	

	T_device = Direct3DCreate9(31);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;


	T_device->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
	T_window,D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &T_d3dDevice);

	// Turn off culling, so we see the front and back of the triangle
	T_d3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	// Turn off D3D lighting, since we are providing our own vertex colors
	T_d3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
}

void DirectXEngine::Redraw()
{
	T_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0);
	T_d3dDevice->BeginScene();
	
	vector<GraphicObject*>* objects = 
		ObjectStorage::Inst().GetCurrentScene()->GetAll();
	for (int i = 0; i < objects->size(); i++)
	{
		(*objects)[i]->Draw();
	}

	T_d3dDevice->EndScene();
	T_d3dDevice->Present(NULL, NULL, NULL, NULL);
}



IDirect3DDevice9* DirectXEngine::GetDevice()
{
	return T_d3dDevice;
}
