#pragma once
#include "raylib.h"
#include "raymath.h"
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void Draw();
	virtual void Update(float dt);

	const Vector2& GetPosition() const;
	const Vector2& GetFaceRotation() const;
	const float& GetRadius() const;
	const int& GetLives() const;
	void SetFaceRotation(const Vector2& dir);
	void SetPosition(const Vector2& pos);
	void SetRadius(const float& rad);
	void SetLives(const int& lives);


protected:
	Vector2 m_pos = { 0, 0 };//Position
	
	Vector2 m_facingDir = { 0, -1 };
	float m_speed = 5;
	float m_radius;
	int m_lives;
private:

};

