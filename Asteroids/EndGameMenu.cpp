#include "EndGameMenu.h"

EndGameMenu::EndGameMenu()
{
	m_restartButtonText = LoadTexture("./assets/reset.png");
	m_restartMenuPos = { (float)GetScreenWidth() / 2, 500 };
	twrestart = (float)m_restartButtonText.width / 10;
	threstart = (float)m_restartButtonText.height / 10;
}

EndGameMenu::~EndGameMenu()
{
}

void EndGameMenu::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	DrawText("Game Over", GetScreenWidth() / 2.75f, 100, 100, BLACK);
	DrawText(FormatText("Score: %i", m_score), GetScreenWidth() / 2.75f, 200, 50, BLACK);//Creates the text for the score.
	DrawTexturePro(m_restartButtonText, { 0, 0, (float)m_restartButtonText.width, (float)m_restartButtonText.height},
		{ m_restartMenuPos.x, m_restartMenuPos.y, twrestart, threstart }, { twrestart * 0.5f, threstart * 0.5f }, 0, WHITE);
	EndDrawing();
}

void EndGameMenu::Update(float dt)
{
	isRestarting();
}

bool EndGameMenu::isRestarting()
{
	Vector2 mousePos = { GetMouseX(), GetMouseY() };
	if (IsMouseButtonPressed(0)
		&& m_restartMenuPos.x + twrestart > mousePos.x && m_restartMenuPos.x < mousePos.x + twrestart
		&& m_restartMenuPos.y + threstart > mousePos.y && m_restartMenuPos.y < mousePos.y + threstart)
		return true;

	return false;
}

void EndGameMenu::retreiveScore(int score)
{
	m_score = score;
}
