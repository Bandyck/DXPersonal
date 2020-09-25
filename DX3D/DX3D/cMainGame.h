#pragma once
class cCubePC;
class cCamera;
class cGrid;
class cHead;
class cBody;
class cLimb;

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
	
	//cCubePC*				m_pCubePC;
	cHead*					m_pHead;
	cBody*					m_pBody;
	cLimb*					m_pLimb;
	cCamera*				m_pCamera;
	cGrid*					m_pGrid;


public:
	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

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