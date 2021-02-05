#pragma once
#include "raylib.h"
class StartMenu
{
public:
	StartMenu();
	~StartMenu();

	void Update(float dt);
	void Draw();
	bool isStarting();
protected:
	bool m_isStarting = false;

	Texture2D m_startButtonText;
	Texture2D m_instrucButtonText;
	Vector2 m_startMenuPos;
	Vector2 m_instrucMenuPos;
	float twStart;
	float thStart;
	float twInst;
	float thInst;

private:

};

