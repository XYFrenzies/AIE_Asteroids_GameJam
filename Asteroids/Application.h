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
	float countTime = 0;
	int spawnTimer = 10;
	Player* m_player;
	std::list<Bullets*> m_bullets;
	std::list<Asteroids*> m_asteroids;

};

