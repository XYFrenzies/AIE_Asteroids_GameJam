#pragma once
#include "raylib.h"
#include "GameObject.h"
class Application;


class Player : public GameObject
{
public:
	Player(Application* app);
	~Player();
	void Draw();
	void Update(float dt);
protected:
private:
	Application* m_app;
	Texture2D m_playerTexture;
};

