#include "Application.h"
#include "raylib.h"
#include <ctime>
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "StartMenu.h"
#include "EndGameMenu.h"

Application::Application() : m_screenWidth(), m_screenHeight()
{
}

Application::~Application()
{
}

void Application::Startup()
{
	m_screenWidth = 1800;
	m_screenHeight = 1000;
	InitWindow(m_screenWidth, m_screenHeight, "Asteroids Game");
	SetTargetFPS(60);
}

void Application::Run()
{
	while (!WindowShouldClose())
	{
		// Main game loop
		StartMenu begin;
		while (begin.isStarting() == false && !WindowShouldClose())
		{
			float dt = GetFrameTime();
			if (dt > 1.0f / 12.0f)
				dt = 1.0f / 12.0f;
			begin.Update(dt);
			begin.Draw();
		}
		if (begin.isStarting() == true || restart == true)
		{
			restart = false;
			Load();
			while (!WindowShouldClose() && m_lives > 0)    // Detect window close button or ESC key
			{
				float dt = GetFrameTime();
				if (dt > 1.0f / 12.0f)
					dt = 1.0f / 12.0f;
				Update(dt);
				Draw();
			}
			Unload();
		}
		if (m_lives <= 0)
		{
			EndGameMenu endMenu;
			while (!WindowShouldClose() && endMenu.isRestarting() != true)
			{
				float dt = GetFrameTime();
				if (dt > 1.0f / 12.0f)
					dt = 1.0f / 12.0f;
				endMenu.retreiveScore(m_score);
				endMenu.Draw();
				endMenu.Update(dt);
			}
			m_lives = 3;
			m_score = 0;
			restart = true;
		}
	}

}

void Application::Update(float dt)
{
	m_player->Update(dt);
	if (IsMouseButtonPressed(0))
	{
		Bullets* newBull = new Bullets(this);
		newBull->SetFaceRotation(GetPlayer()->GetFaceRotation());
		newBull->SetPosition(GetPlayer()->GetPosition());
		m_bullets.push_back(newBull);
	}
	if (countTime > spawnTimer)
	{
		Vector2 newRandLoc = { (float)GetRandomValue(500, GetScreenWidth() - 500), (float)GetRandomValue(300, GetScreenHeight() - 300) };//Position to travel to.
		Asteroids* newAsteroid = new Asteroids(this);
		newAsteroid->SetPosition(RandomNumberGenerator());
		newAsteroid->SetFaceRotation(Vector2Normalize({ newRandLoc.x - RandomNumberGenerator().x, newRandLoc.y - RandomNumberGenerator().y }));
		newAsteroid->SetRadius(40);
		m_asteroids.push_back(newAsteroid);
		countTime = 0;
	}
	else
		countTime += 1;

	std::list<Asteroids*> asteroidsToDelete;
	std::list<Bullets*> bulletsToDelete;
	//This is to decrease the live of the player, it also destroys the asteroid as well for now
	for (auto asteroids : m_asteroids)
	{
		if (asteroids->GetPosition().x + asteroids->GetRadius() > m_player->GetPosition().x
			&& asteroids->GetPosition().x < m_player->GetPosition().x + asteroids->GetRadius() + m_player->GetRadius()
			&& asteroids->GetPosition().y + asteroids->GetRadius() > m_player->GetPosition().y
			&& asteroids->GetPosition().y < m_player->GetPosition().y + asteroids->GetRadius() + m_player->GetRadius())
		{
			m_lives--;
			asteroidsToDelete.push_back(asteroids);
		}
	}
	for (auto bullets : m_bullets)
	{
		if (bullets->GetPosition().x + bullets->GetRadius() > GetScreenWidth())
			bulletsToDelete.push_back(bullets);
		if (bullets->GetPosition().x - bullets->GetRadius() < 0)
			bulletsToDelete.push_back(bullets);
		if (bullets->GetPosition().y + bullets->GetRadius() > GetScreenHeight())
			bulletsToDelete.push_back(bullets);
		if (bullets->GetPosition().y - bullets->GetRadius() < 0)
			bulletsToDelete.push_back(bullets);
		for (auto asteroids : m_asteroids)
		{
			if (asteroids->GetPosition().x + asteroids->GetRadius() > bullets->GetPosition().x
				&& asteroids->GetPosition().x < bullets->GetPosition().x + asteroids->GetRadius() + bullets->GetRadius()
				&& asteroids->GetPosition().y + asteroids->GetRadius() > bullets->GetPosition().y
				&& asteroids->GetPosition().y < bullets->GetPosition().y + asteroids->GetRadius() + bullets->GetRadius())
			{
				asteroidsToDelete.push_back(asteroids);
				bulletsToDelete.push_back(bullets);
				m_score += 10;
				break;
			}
		}
	}
	for (auto bulletToDelete : bulletsToDelete)
		m_bullets.remove(bulletToDelete);

	for (auto asteroidToDelete : asteroidsToDelete)
		m_asteroids.remove(asteroidToDelete);

	for (auto bullets : m_bullets)
		bullets->Update(dt);
	for (auto asteroids : m_asteroids)
		asteroids->Update(dt);
}
Vector2 Application::RandomNumberGenerator()
{
	int count = GetRandomValue(1, 4);//Determines what part of the screen an object spawns.
	Vector2 value;
	switch (count)
	{
	case 1:
		value = { (float)GetRandomValue(-100, m_screenWidth + 100), (float)GetRandomValue(-100, -10) };//This is the top of the screen.
		break;
	case 2:
		value = { (float)GetRandomValue(-100, -10), (float)GetRandomValue(-10, m_screenHeight + 10) };//Left of the screen.
		break;
	case 3:
		value = { (float)GetRandomValue(m_screenWidth + 10, m_screenWidth + 100), (float)GetRandomValue(-10,  m_screenHeight + 10) };//Right of the screen.
		break;
	case 4:
		value = { (float)GetRandomValue(-100, m_screenWidth + 100), (float)GetRandomValue(m_screenHeight + 10, m_screenHeight + 100) };//Bottom of the screen.
		break;
	}
	return value;
}


void Application::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	for (auto bullet : m_bullets)
		bullet->Draw();
	m_player->Draw();
	for (auto asteroid : m_asteroids)
		asteroid->Draw();
	DrawText(FormatText("Score: %i", m_score), 10, 10, 50, RAYWHITE);//Creates the text for the score.
	DrawText("Lives:", 10, 70, 50, RAYWHITE);
	xPosHeart = 220;

	for (size_t i = 0; i < m_lives; i++)
	{
		DrawTexturePro(m_heartTexture, { 0, 0, (float)m_heartTexture.width, (float)m_heartTexture.height },
			{ xPosHeart, 95,  twHeart,  thHeart }, { twHeart * 0.5f, thHeart * 0.5f }, 0, WHITE);
		xPosHeart += 100;
	}


	EndDrawing();
}

void Application::Load()
{
	m_heartTexture = LoadTexture("./assets/heart.png");
	twHeart = (float)m_heartTexture.width / 35;//Determining the heart size in the width
	thHeart = (float)m_heartTexture.height / 35;//Determining the heart size in the height;
	m_player = new Player(this);
	m_player->SetPosition({ m_screenWidth * 0.25f, m_screenHeight * 0.25f });
	m_player->SetLives(3);
	m_player->SetRadius(40);
	m_lives = GetPlayer()->GetLives();
}

void Application::Unload()
{
	delete m_player;
	m_player = nullptr;

	for (auto bullet : m_bullets)
		delete bullet;
	for (auto asteroid : m_asteroids)
		delete asteroid;
	m_bullets.clear();
	m_asteroids.clear();
	
}
Player* Application::GetPlayer()//Gets the values of player
{
	return m_player;
}
std::list<Bullets*>& Application::GetBullets()//Gets the values of player
{
	return m_bullets;
}

std::list<Asteroids*>& Application::GetAsteroids()//Gets the values of player
{
	return m_asteroids;
}

