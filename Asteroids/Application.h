#pragma once
#include "raylib.h"
#include "Player.h"
#include "Bullets.h"
#include "Asteroids.h"
class Application
{
public:
	Application();
	virtual ~Application();
	void Startup();//Starts game;
	void Run();//Runs draw and update for game;
	void Update(float dt);
	void Draw();

	void Load();
	void Unload();
	Player* GetPlayer();//Gets the players information from a point in memory
	std::list<Asteroids*>& GetAsteroids();
	std::list<Bullets*>& GetBullets();
	Vector2 RandomNumberGenerator();


protected:
private:
	int m_screenWidth;
	int m_screenHeight;
	int m_score = 0;
	float countTime = 0;
	float twHeart;
	float thHeart;
	int spawnTimer = 2;
	int m_lives;
	float xPosHeart;
	Player* m_player;
	std::list<Bullets*> m_bullets;
	std::list<Asteroids*> m_asteroids;
	Texture2D m_heartTexture;
	bool restart = false;

};

