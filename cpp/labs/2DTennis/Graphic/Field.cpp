#include "Field.h"
#include "Controller.h"

using namespace Graphics;


Field::Field(GraphicEngine* engine):
	DirectXObject(engine)
{
	static CUSTOMVERTEX bg[] = 
	{
		{ -1.0f, -1.0f, 0, D3DCOLOR_XRGB(155,155, 23),},
		{ 1.0f, -1.0f, 0, D3DCOLOR_XRGB(45,13, 182),},
		{ -1.0f, 1.0f, 0, D3DCOLOR_XRGB(82,139, 45),},
		{ 1.0f, 01.0f, 0, D3DCOLOR_XRGB(241,56, 87),}
	};

	T_d3dDevice->CreateVertexBuffer( 4*sizeof(CUSTOMVERTEX),
         0 , D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &T_bg, NULL );

	VOID* pBG;
	long hRes = T_bg->Lock( 0, sizeof(bg), (void**)&pBG, 0 );
	if (FAILED(hRes))
		exit(0);
    memcpy( pBG, bg, sizeof(bg) );
	T_bg->Unlock();


	static CUSTOMVERTEX vertices1[] = 
	{
		{ -0.95f, -0.8f, 0, D3DCOLOR_XRGB(82,139, 182),},
		{ 0.95f, -0.8f, 0, D3DCOLOR_XRGB(82,139, 182),},
		{ -0.45f, 0.8f, 0, D3DCOLOR_XRGB(82,139, 182),},
		{ 0.45f, 0.8f, 0, D3DCOLOR_XRGB(82,139, 182),}
	};
	T_vertices = vertices1;

	T_d3dDevice->CreateVertexBuffer( 4*sizeof(CUSTOMVERTEX),
         0 , D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &T_vb, NULL );

	VOID* pVertices;
	hRes = T_vb->Lock( 0, sizeof(vertices1), (void**)&pVertices, 0 );
	if (FAILED(hRes))
		exit(0);
    memcpy( pVertices, vertices1, sizeof(vertices1) );
	T_vb->Unlock();

	static CUSTOMVERTEX vertices2[] = 
	{
		{ -0.95f, -0.8f, 0, D3DCOLOR_XRGB(2,100, 21),},
		{ 0.95f, -0.8f, 0, D3DCOLOR_XRGB(2,100, 21),},
		{ -0.45f, 0.8f, 0, D3DCOLOR_XRGB(2,100, 21),},
		{ 0.45f, 0.8f, 0, D3DCOLOR_XRGB(2,100, 21),}
	};
	T_vertices = vertices2;

	T_d3dDevice->CreateVertexBuffer( 4*sizeof(CUSTOMVERTEX),
         0 , D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &T_field2, NULL );

	VOID* pVertices3;
	hRes = T_field2->Lock( 0, sizeof(vertices2), (void**)&pVertices3, 0 );
	if (FAILED(hRes))
		exit(0);
    memcpy( pVertices3, vertices2, sizeof(vertices2) );
	T_field2->Unlock();

	static CUSTOMVERTEX vertices3[] = 
	{
		{ -0.95f, -0.8f, 0, D3DCOLOR_XRGB(136,52, 0),},
		{ 0.95f, -0.8f, 0, D3DCOLOR_XRGB(136,52, 0),},
		{ -0.45f, 0.8f, 0, D3DCOLOR_XRGB(136,52, 0),},
		{ 0.45f, 0.8f, 0, D3DCOLOR_XRGB(136,52, 0),}
	};
	T_vertices = vertices2;

	T_d3dDevice->CreateVertexBuffer( 4*sizeof(CUSTOMVERTEX),
         0 , D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &T_field3, NULL );

	VOID* pVertices4;
	hRes = T_field3->Lock( 0, sizeof(vertices3), (void**)&pVertices4, 0 );
	if (FAILED(hRes))
		exit(0);
    memcpy( pVertices4, vertices3, sizeof(vertices3) );
	T_field3->Unlock();

	static CUSTOMVERTEX lines[] = 
	{
		{ -0.95f, -0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ -0.45f, 0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ -0.45f, 0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.45f, 0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ 0.45f, 0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.95f, -0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ 0.95f, -0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ -0.95f, -0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ -0.75f, -0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ -0.35f, 0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ 0.75f, -0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.35f, 0.8f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ -0.62f, 0.25f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.62f, 0.25f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ -0.6f, -0.2f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.6f, -0.2f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ -0.41f, 0.55f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.41f, 0.55f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ 0.0f, -0.2f, 0, D3DCOLOR_XRGB(255,255, 255),},
		{ 0.0f, 0.55f, 0, D3DCOLOR_XRGB(255,255, 255),},
		//--------------------------------------------
		{ -0.62f, 0.4f, 0, D3DCOLOR_XRGB(228,254, 46),},
		{ 0.62f, 0.4f, 0, D3DCOLOR_XRGB(228,254, 46),},
		//--------------------------------------------
		{ -0.62f, 0.4f, 0, D3DCOLOR_XRGB(228,254, 46),},
		{ 0.62f, 0.25f, 0, D3DCOLOR_XRGB(228,254, 46),},
		//--------------------------------------------
		{ -0.62f, 0.25f, 0, D3DCOLOR_XRGB(228,254, 46),},
		{ 0.62f, 0.4f, 0, D3DCOLOR_XRGB(228,254, 46),},
	};

	T_d3dDevice->CreateVertexBuffer( 26*sizeof(CUSTOMVERTEX),
         0 , D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &T_lines, NULL );

	VOID* pVertices2;
	hRes= T_lines->Lock( 0, sizeof(lines), (void**)&pVertices2, 0 );
	if (FAILED(hRes))
		exit(0);
    memcpy( pVertices2, lines, sizeof(lines) );
	T_lines->Unlock();
}

Field::~Field(void)
{
}


void Field::Update(int dt)
{
}

void Field::Draw()
{
	switch (Controller::GetField())
	{
	case 1:
		T_d3dDevice->SetStreamSource( 0, T_vb, 0, sizeof( CUSTOMVERTEX ) );
		break;
	case 2:
		T_d3dDevice->SetStreamSource( 0, T_field2, 0, sizeof( CUSTOMVERTEX ) );
		break;
	case 3:
		T_d3dDevice->SetStreamSource( 0, T_field3, 0, sizeof( CUSTOMVERTEX ) );
		break;
	}
    T_d3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
    T_d3dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2 );

	T_d3dDevice->SetStreamSource( 0, T_lines, 0, sizeof( CUSTOMVERTEX ) );
    T_d3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
    T_d3dDevice->DrawPrimitive( D3DPT_LINELIST, 0,  13);

	
}

void Field::FreeResources()
{
}