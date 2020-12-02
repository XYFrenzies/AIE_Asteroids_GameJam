#pragma once
#include "GameObject.h"
#include <list>
class Application;
class Bullets : public GameObject
{
public:
	Bullets(Application* app);

	virtual ~Bullets();

	void Update(float dt);
	
	void Draw();
protected:
	
private:
	Application* m_app;
};

