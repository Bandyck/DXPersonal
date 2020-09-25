#pragma once
class cLimb
{
public:
	cLimb();
	~cLimb();
private:
	vector<ST_PC_VERTEX>	m_vecVertex[4];
	enum Limb : int
	{
		left_arm = 0, right_arm, left_leg, right_leg
	};
	float					m_fRotX, m_fRotY;
	D3DXVECTOR3				m_vDirection;
	D3DXVECTOR3				m_vPosition;
	D3DXMATRIXA16			m_matWorld;
public:
	void Setup();
	void Update();
	void Render();
	D3DXVECTOR3 &			GetPosition();
};