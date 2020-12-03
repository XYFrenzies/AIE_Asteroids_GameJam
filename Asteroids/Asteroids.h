#pragma once
#include "GameObject.h"
class Application;
class Asteroids : public GameObject
{
public:
	Asteroids(Application* app);
	virtual ~Asteroids();
	virtual void Draw();
	virtual void Update(float dt);
protected:
	Vector2 randomLoc;
private:
	Texture2D asteroidText;
	Application* m_app;
	float m_asteroidSpeed;
	bool isOutOfSpace = false;
};

