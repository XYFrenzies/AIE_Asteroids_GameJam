#include "Asteroids.h"
#include "Application.h"
Asteroids::Asteroids(Application* app)
{
	m_app = app;
	asteroidText = LoadTexture("./assets/asteroid.png");
	randomLoc = { (float)GetRandomValue(10, GetScreenWidth() - 10), (float)GetRandomValue(10, GetScreenHeight() - 10) };
	m_asteroidSpeed = (float)GetRandomValue(1, 6);
}

Asteroids::~Asteroids()
{
}

void Asteroids::Draw()
{
	float rot = atan2f(m_facingDir.y, m_facingDir.x) * (180.0f / PI);
	float tw = (float)asteroidText.width / 15;//Tile width
	float th = (float)asteroidText.height / 15;//Tileheight

	DrawTexturePro(asteroidText,
		{ 0.0f, 0.0f, (float)asteroidText.width, (float)asteroidText.height },
		{ m_pos.x, m_pos.y, tw, th },
		{ tw * 0.5f, th * 0.5f }, rot, WHITE);
}

void Asteroids::Update(float dt)
{
	m_pos.x += GetFaceRotation().x * m_asteroidSpeed;
	m_pos.y += GetFaceRotation().y * m_asteroidSpeed;
}
