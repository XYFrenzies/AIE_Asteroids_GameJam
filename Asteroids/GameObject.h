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

	void SetFaceRotation(const Vector2& dir);
	void SetPosition(const Vector2& pos);


protected:
	Vector2 m_pos = { 0, 0 };//Position

	Vector2 m_facingDir = { 0, -1 };
	float m_speed = 5;
private:

};

