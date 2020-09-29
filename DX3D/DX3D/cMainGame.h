#pragma once
class cCubePC;
class cCamera;
class cGrid;
class cCubeMan;
//class cHead;
//class cBody;
//class cLimb;

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	/// 내 선언
	//{
	//vector<ST_PC_VERTEX>	m_vecLineVertex;
	//vector<ST_PC_VERTEX>	m_vecTriangleVertex;
	//vector<ST_PC_VERTEX>	m_vecGridVertex;
	//vector<ST_PC_VERTEX>	m_vecXaxisVertex;
	//vector<ST_PC_VERTEX>	m_vecYaxisVertex;
	//vector<ST_PC_VERTEX>	m_vecZaxisVertex;
	//vector<ST_PC_VERTEX>	m_vecCubeVertex;
	//}
	vector<ST_PC_VERTEX>	m_vecLineVertex;
	vector<ST_PC_VERTEX>	m_vecTriangleVertex;
	
	cCubePC*				m_pCubePC;
	cCamera*				m_pCamera;
	cGrid*					m_pGrid;
	cCubeMan*				m_pCubeMan;

	// >> : for texture
	LPDIRECT3DTEXTURE9		m_pTexture;
	vector<ST_PT_VERTEX>	m_vecVertex;
	// << : 

	/// 내 코드
	//cHead*					m_pHead;
	//cBody*					m_pBody;
	//cLimb*					m_pLimb;

public:
	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Set_Light();
	void Draw_Texture();
	/// 내 선언
	//{
	//	void Setup_Line();
	//	void Draw_Line();
	//
	//	void Setup_Triangle();
	//	void Draw_Triangle();
	//
	//	void Setup_Grid();
	//	void Draw_Grid();
	//
	//	void Setup_Axis();
	//	void Draw_Axis();
	//
	//	void Setup_Cube();
	//	void Draw_Cube();
	//}
};