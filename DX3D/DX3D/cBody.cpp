#include "stdafx.h"
#include "cBody.h"

cBody::cBody()
	: m_vDirection(0, 0, 1)
	, m_vPosition(0, 0, 0)
	, m_fRotY(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
}
cBody::~cBody()
{
}
void cBody::Setup()
{
	ST_PC_VERTEX v;

	v.c = D3DCOLOR_XRGB(228, 210, 122);
	// front
	{
		v.p = D3DXVECTOR3(-0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
	}
	// back
	{
		v.p = D3DXVECTOR3(-0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
	}
	// left
	{
		v.p = D3DXVECTOR3(-0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
	}
	// right
	{
		v.p = D3DXVECTOR3(0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
	}
	// top
	{
		v.p = D3DXVECTOR3(-0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 2.0f, -0.25f);
		m_vecVertex.push_back(v);
	}
	// bottom
	{
		v.p = D3DXVECTOR3(-0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 1.0f, -0.25f);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(0.5f, 1.0f, 0.25f);
		m_vecVertex.push_back(v);
	}
}
void cBody::Update()
{
	if (GetKeyState('A') & 0X8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0X8000)
	{
		m_fRotY += 0.1f;
	}
	if (GetKeyState('W') & 0X8000)
	{
		m_vPosition += (m_vDirection*0.1f);
	}
	if (GetKeyState('S') & 0X8000)
	{
		m_vPosition -= (m_vDirection*0.1f);
	}

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}
void cBody::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, false);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}
D3DXVECTOR3 & cBody::GetPosition()
{
	return m_vPosition;
}