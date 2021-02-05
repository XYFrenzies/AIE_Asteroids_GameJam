#pragma once
#include "raylib.h"
class EndGameMenu
{
public:
	EndGameMenu();
	~EndGameMenu();
	void Draw();
	void Update(float dt);
	bool isRestarting();
	void retreiveScore(int score);
protected:
	Texture2D m_restartButtonText;
	Vector2 m_restartMenuPos;
	float twrestart;
	float threstart;
	int m_score;
private:
};

