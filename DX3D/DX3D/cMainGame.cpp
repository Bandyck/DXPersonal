#include "stdafx.h"
#include "cMainGame.h"
#include "cDiveceManager.h"
#include "cCamera.h"
#include "cCubePC.h"
#include "cGrid.h"
#include "cCubeMan.h"
//#include "cHead.h"
//#include "cBody.h"
//#include "cLimb.h"

cMainGame::cMainGame() 
	: m_pCubePC(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pCubeMan(NULL)
	, m_pTexture(NULL)
	//, m_pHead(NULL)
	//, m_pLimb(NULL)
{
}
cMainGame::~cMainGame()
{
	SafeDelete(m_pCubePC);
	SafeDelete(m_pCamera);
	SafeDelete(m_pGrid);
	SafeDelete(m_pCubeMan);
	SafeRelease(m_pTexture);
	g_pDeviceManager->Destroy();
	//SafeDelete(m_pHead);
}
/// 내 셋업
//void cMainGame::Setup()
//{
//	m_p3D = Direct3DCreate9(D3D_SDK_VERSION);
//
//	D3DCAPS9 caps;
//	m_p3D->GetDeviceCaps(
//		D3DADAPTER_DEFAULT, 
//		D3DDEVTYPE_HAL, 
//		&caps);
//	
//	int vp = 0;
//	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
//		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
//	else
//		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
//
//	D3DPRESENT_PARAMETERS d3dpp;
//	ZeroMemory(&d3dpp, sizeof(d3dpp));
//	d3dpp.Windowed = true;
//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
//	d3dpp.BackBufferCount = 1;
//	d3dpp.EnableAutoDepthStencil = true;
//	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
//
//	m_pDevice = 0;
//	m_p3D->CreateDevice(
//		D3DADAPTER_DEFAULT, 
//		D3DDEVTYPE_HAL, 
//		g_hWnd, 
//		D3DCREATE_HARDWARE_VERTEXPROCESSING,
//		&d3dpp, 
//		&m_pDevice);
//}
/// 내 렌더
//void cMainGame::Render()
//{
//	if (m_pDevice)
//	{
//		m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x000000FF, 1.0f, 0);
//		m_pDevice->Present(0, 0, 0, 0);
//	}
//}
void cMainGame::Setup()
{
	//Setup_Grid();
	//Setup_Line();
	//Setup_Axis();
	//Setup_Cube();
	//Setup_Triangle();
	//m_pHead = new cHead;
	//m_pHead->Setup();
	//m_pBody = new cBody;
	//m_pBody->Setup();
	//m_pLimb = new cLimb;
	//m_pLimb->Setup();

	m_pCubePC = new cCubePC;
	m_pCubePC->Setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubeMan->GetPosition());
	// m_pCamera->Setup(&m_pCubePC->GetPosition());
	// m_pCamera->Setup(&m_pHead->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	// >> : for texture
	{
		D3DXCreateTextureFromFile(g_pD3DDevice, L"수지.bmp", &m_pTexture);
		ST_PT_VERTEX v;
		v.p = D3DXVECTOR3(0, 0, 0);
		v.t = D3DXVECTOR2(0, 1);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(0, 1, 0);
		v.t = D3DXVECTOR2(0, 0);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(1, 1, 0);
		v.t = D3DXVECTOR2(1, 0);
		m_vecVertex.push_back(v);

	}
	// << :
	Set_Light();
	// 조명 끄기
	// g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}
void cMainGame::Update()
{
	//RECT rc;
	//GetClientRect(g_hWnd, &rc);
	//D3DXVECTOR3 vEye = D3DXVECTOR3(20.0f, 20.0f, -20.0f);
	//D3DXVECTOR3 vLookAt = D3DXVECTOR3(0, 0, 0);
	//D3DXVECTOR3 vUp = D3DXVECTOR3(0, 1, 0);
	//D3DXMATRIXA16 matView;
	//D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
	//g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
	//D3DXMATRIXA16 matProj;
	//D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0f, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	//g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
	//if (m_pCubePC)
	//	m_pCubePC->Update();
	//if (m_pHead)
	//	m_pHead->Update();
	//if (m_pBody)
	//	m_pBody->Update();
	//if (m_pLimb)
	//	m_pLimb->Update();

	if (m_pCubeMan)
		m_pCubeMan->Update();
	if (m_pCamera)
		m_pCamera->Update();
}
void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(47, 121, 112), 1.0F, 0);

	g_pD3DDevice->BeginScene();
	//Draw_Line();
	//Draw_Grid();
	//Draw_Axis();
	//Draw_Cube();
	//Draw_Triangle();
	//if (m_pCubePC)
	//	m_pCubePC->Render();
	//if (m_pLimb)
	//	m_pLimb->Render();
	//if (m_pBody)
	//	m_pBody->Render();
	//if (m_pHead)
	//	m_pHead->Render();

	if (m_pGrid)
		m_pGrid->Render();
	Draw_Texture();
	//if (m_pCubeMan)
	//	m_pCubeMan->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}
void cMainGame::Set_Light()
{
	D3DLIGHT9	stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_DIRECTIONAL;
	stLight.Ambient = D3DXCOLOR(0.8F, 0.8F, 0.8F, 1.0F);
	stLight.Diffuse = D3DXCOLOR(0.8F, 0.8F, 0.8F, 1.0F);
	stLight.Specular = D3DXCOLOR(0.8F, 0.8F, 0.8F, 1.0F);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;
	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);
}
void cMainGame::Draw_Texture()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PT_VERTEX));
	// 텍스쳐값 다시 초기화
	g_pD3DDevice->SetTexture(0, NULL);
}
//void cMainGame::Setup_Line()
//{
//	ST_PC_VERTEX v;
//
//	// x축
//	{
//		v.c = D3DCOLOR_XRGB(255, 0, 0);
//		v.p = D3DXVECTOR3(15, 0, 0);
//		m_vecLineVertex.push_back(v);
//		v.p = D3DXVECTOR3(-15, 0, 0);
//		m_vecLineVertex.push_back(v);
//	}
//	// y축
//	{
//		v.c = D3DCOLOR_XRGB(0, 255, 0);
//		v.p = D3DXVECTOR3(0, 15, 0);
//		m_vecLineVertex.push_back(v);
//		v.p = D3DXVECTOR3(0, -15, 0);
//		m_vecLineVertex.push_back(v);
//	}
//	// z축
//	{
//		v.c = D3DCOLOR_XRGB(0, 0, 255);
//		v.p = D3DXVECTOR3(0, 0, 15);
//		m_vecLineVertex.push_back(v);
//		v.p = D3DXVECTOR3(0, 0, -15);
//		m_vecLineVertex.push_back(v);
//	}
//}
//void cMainGame::Draw_Line()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecLineVertex.size() / 2, &m_vecLineVertex[0], sizeof(ST_PC_VERTEX));
//}
//void cMainGame::Setup_Triangle()
//{
//	ST_PC_VERTEX v;
//	v.c = D3DCOLOR_XRGB(0, 255, 0);
//	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
//	m_vecTriangleVertex.push_back(v);
//
//	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
//	m_vecTriangleVertex.push_back(v);
//
//	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
//	m_vecTriangleVertex.push_back(v);
//}
//void cMainGame::Draw_Triangle()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//
//	D3DXVECTOR3 vPosition = D3DXVECTOR3(0, 0, 0);
//	D3DXMatrixTranslation(&matWorld, vPosition.x, vPosition.y, vPosition.z);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);		// 라인에서 적용된 거라 주석처리 해도 됨. 바꾸거나 단독으로 쓰일 경우는 적자.
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTriangleVertex.size() / 3, &m_vecTriangleVertex[0], sizeof(ST_PC_VERTEX));
//}
//void cMainGame::Setup_Grid()
//{
//	ST_PC_VERTEX v;
//	for (int i = -15; i <= 15; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			if (j % 2 == 0)
//				v.p = D3DXVECTOR3(i, 0, -15);
//			else
//				v.p = D3DXVECTOR3(i, 0, 15);
//			if (i % 5 == 0)
//				v.c = D3DCOLOR_XRGB(255, 255, 255);
//			else
//				v.c = D3DCOLOR_XRGB(195, 195, 195);
//			m_vecGridVertex.push_back(v);
//		}
//	}
//	for (int i = -15; i <= 15; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			if (j % 2 == 0)
//				v.p = D3DXVECTOR3(-15, 0, i);
//			else
//				v.p = D3DXVECTOR3(15, 0, i);
//			if (i % 5 == 0)
//				v.c = D3DCOLOR_XRGB(255, 255, 255);
//			else
//				v.c = D3DCOLOR_XRGB(195, 195, 195);
//			m_vecGridVertex.push_back(v);
//		}
//	}
//}
//void cMainGame::Draw_Grid()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecGridVertex.size() / 2, &m_vecGridVertex[0], sizeof(ST_PC_VERTEX));
//}
//void cMainGame::Setup_Axis()
//{
//	ST_PC_VERTEX v;
//	// x축 Gizmo
//	{
//		v.c = D3DCOLOR_XRGB(255, 0, 0);
//		v.p = D3DXVECTOR3(0, 0, 0);
//		m_vecXaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(3, 0.2f, 0.2f);
//		m_vecXaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(3, 0.2f, -0.2f);
//		m_vecXaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(3, -0.2f, 0.2f);
//		m_vecXaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(3, -0.2f, -0.2f);
//		m_vecXaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0, 0, 0);
//		m_vecXaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(3, 0.2f, -0.2f);
//		m_vecXaxisVertex.push_back(v);
//	}
//	// y축 Gizmo
//	{
//		v.c = D3DCOLOR_XRGB(0, 255, 0);
//		v.p = D3DXVECTOR3(0, 0, 0);
//		m_vecYaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(-0.2f, 3, -0.2f);
//		m_vecYaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0.2f, 3, -0.2f);
//		m_vecYaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(-0.2f, 3, 0.2f);
//		m_vecYaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0.2f, 3, 0.2f);
//		m_vecYaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0, 0, 0);
//		m_vecYaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0.2f, 3, -0.2f);
//		m_vecYaxisVertex.push_back(v);
//	}
//	// z축 Gizmo
//	{
//		v.c = D3DCOLOR_XRGB(0, 0, 255);
//		v.p = D3DXVECTOR3(0, 0, 0);
//		m_vecZaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(-0.2f, 0.2f, 3);
//		m_vecZaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0.2f, 0.2f, 3);
//		m_vecZaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0.2f, -0.2f, 3);
//		m_vecZaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(-0.2f, -0.2f, 3);
//		m_vecZaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0, 0, 0);
//		m_vecZaxisVertex.push_back(v);
//		v.p = D3DXVECTOR3(0.2f, 0.2f, 3);
//		m_vecZaxisVertex.push_back(v);
//	}
//}
//void cMainGame::Draw_Axis()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);		
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 5, &m_vecXaxisVertex[0], sizeof(ST_PC_VERTEX));
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 5, &m_vecYaxisVertex[0], sizeof(ST_PC_VERTEX));
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 5, &m_vecZaxisVertex[0], sizeof(ST_PC_VERTEX));
//
//}
//void cMainGame::Setup_Cube()
//{
//	ST_PC_VERTEX v;
//	{
//		v.p = D3DXVECTOR3(-1, -1, -1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(-1, 1, -1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(1, 1, -1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(1, -1, -1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(-1, -1, 1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(-1, 1, 1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(1, 1, 1);
//		m_vecCubeVertex.push_back(v);
//		v.p = D3DXVECTOR3(1, -1, 1);
//		m_vecCubeVertex.push_back(v);
//	}
//}
//void cMainGame::Draw_Cube()
//{
//	D3DXMATRIXA16 matWorld;
//	D3DXMatrixIdentity(&matWorld);
//
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 3, &m_vecCubeVertex[0], sizeof(ST_PC_VERTEX));
//
//}