#include "stdafx.h"
#include "cLimb.h"

cLimb::cLimb()
	: m_vDirection(0, 0, 1)
	, m_vPosition(0, 0, 0)
	, m_fRotX(0.0f)
	, m_fRotY(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
}
cLimb::~cLimb()
{
}
void cLimb::Setup()
{
	ST_PC_VERTEX v;

	v.c = D3DCOLOR_XRGB(216, 188, 61);
	for (int i = left_arm; i <= right_arm; i++)
	{
		int flag;
		if (i % 2 == 0)
			flag = -1;
		else
			flag = 1;
		// front
		{
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
		}
		// back
		{
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
		}
		// left
		{
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
		}
		// right
		{
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
		}
		// top
		{
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 2.0f, -0.25f);
			m_vecVertex[i].push_back(v);
		}
		// bottom
		{
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.75f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
		}

	}
	for (int i = left_leg; i <= right_leg; i++)
	{
		int flag;
		if (i % 2 == 0)
			flag = -1;
		else
			flag = 1;
		// front
		{
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
		}
		// back
		{
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
		}
		// left
		{
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
		}
		// right
		{
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
		}
		// top
		{
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 1.0f, -0.25f);
			m_vecVertex[i].push_back(v);
		}
		// bottom
		{
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);

			v.p = D3DXVECTOR3(-0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, -0.25f);
			m_vecVertex[i].push_back(v);
			v.p = D3DXVECTOR3(0.25f+0.25f*flag, 0.0f, 0.25f);
			m_vecVertex[i].push_back(v);
		}
	}
}
void cLimb::Update()
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
	//m_fRotX += 0.001f;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	//D3DXMATRIXA16 matSwing;
	//D3DXMatrixRotationX(&matSwing, m_fRotX);

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}
void cLimb::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, false);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	for(int i= 0;i<=right_leg;i++)
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex[i].size() / 3, &m_vecVertex[i][0], sizeof(ST_PC_VERTEX));
}
D3DXVECTOR3 & cLimb::GetPosition()
{
	return m_vPosition;
}