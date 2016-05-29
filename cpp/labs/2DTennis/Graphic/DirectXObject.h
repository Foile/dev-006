#pragma once
#include "GraphicObject.h"
#include "d3d9.h"
#include "DirectXEngine.h"

namespace Graphics
{

	class DirectXObject :
		public GraphicObject
	{
	protected:
		IDirect3DDevice9 * T_d3dDevice;
		IDirect3DVertexBuffer9 *T_vb;
		CUSTOMVERTEX  *T_vertices;
		float T_view;
		D3DXMATRIXA16 T_matrix;
		bool T_matrixDeterm;
	public:
		virtual void Update(int dt) = 0;
		virtual void Draw() = 0;
		virtual void Rotate(float x, float y, float z, float degree);
		virtual void SetRotationPoint(float deltaX, float deltaY, float deltaZ);
		virtual void FreeResources() = 0;
		virtual void SetX(float x);
		virtual void SetY(float y);
		DirectXObject(GraphicEngine *d3dDevice);
		~DirectXObject(void);
	};
}