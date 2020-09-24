#pragma once

#define g_pDeviceManager cDiveceManager::GetInstance()
#define g_pD3DDevice cDiveceManager::GetInstance()->GetDevice()
class cDiveceManager
{
	Singletone(cDiveceManager);

private:
	LPDIRECT3D9			m_p3D;
	LPDIRECT3DDEVICE9	m_pD3DDevice;

public:
	LPDIRECT3DDEVICE9	GetDevice();
	void Destroy();
};