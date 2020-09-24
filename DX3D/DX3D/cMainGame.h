#pragma once
class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	vector<ST_PC_VERTEX>	m_vecLineVertex;
	vector<ST_PC_VERTEX>	m_vecTriangleVertex;
	vector<ST_PC_VERTEX>	m_vecGridVertex;
	vector<ST_PC_VERTEX>	m_vecXaxisVertex;
	vector<ST_PC_VERTEX>	m_vecYaxisVertex;
	vector<ST_PC_VERTEX>	m_vecZaxisVertex;
	vector<ST_PC_VERTEX>	m_vecCubeVertex;

public:
	void Setup();
	void Update();
	void Render();

	void Setup_Line();
	void Draw_Line();

	void Setup_Triangle();
	void Draw_Triangle();

	void Setup_Grid();
	void Draw_Grid();

	void Setup_Axis();
	void Draw_Axis();

	void Setup_Cube();
	void Draw_Cube();
};