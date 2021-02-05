#include "StartMenu.h"
#include "raylib.h"
StartMenu::StartMenu()
{
	m_startButtonText = LoadTexture("./assets/StartButton.png");
	m_instrucButtonText = LoadTexture("Instructions.png");
	m_startMenuPos = { (float)GetScreenWidth() / 2, 500 };
	m_instrucMenuPos = { (float)GetScreenWidth() / 2, 900 };
	twStart = (float)m_startButtonText.width / 2;
	thStart = (float)m_startButtonText.height / 2;
	twInst = (float)m_instrucButtonText.width / 2;
	thInst = (float)m_instrucButtonText.height / 2;
}

StartMenu::~StartMenu()
{
}

void StartMenu::Update(float dt)
{
	isStarting();
}

void StartMenu::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	DrawText("Asteroids", GetScreenWidth() / 2.75f, 100, 100, BLACK);
	DrawTexturePro(m_startButtonText, { 0, 0, (float)m_startButtonText.width, (float)m_startButtonText.height },
		{ m_startMenuPos.x, m_startMenuPos.y, twStart, thStart }, { twStart * 0.5f, thStart * 0.5f }, 0, WHITE);
	DrawTexturePro(m_instrucButtonText, { 0, 0, (float)m_instrucButtonText.width, (float)m_instrucButtonText.height },
		{ m_instrucMenuPos.x, m_instrucMenuPos.y , twInst, thInst }, { twInst * 0.5f, thInst * 0.5f }, 0, WHITE);
	EndDrawing();
}

bool StartMenu::isStarting()
{

	Vector2 mousePos = { GetMouseX(), GetMouseY() };
	if (IsMouseButtonPressed(0) 
		&& m_startMenuPos.x + twStart > mousePos.x && m_startMenuPos.x < mousePos.x + twStart
		&& m_startMenuPos.y + thStart > mousePos.y && m_startMenuPos.y < mousePos.y + thStart)
		return true;

	return false;
}
