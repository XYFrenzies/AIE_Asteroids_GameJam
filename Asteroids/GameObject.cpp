#include "GameObject.h"


GameObject::GameObject(): m_pos()
{

}
GameObject::~GameObject()
{
}

void GameObject::Draw()
{
}

void GameObject::Update(float dt)
{
}

const Vector2& GameObject::GetPosition() const
{
	return m_pos;
}

const Vector2& GameObject::GetFaceRotation() const
{
	return m_facingDir;
}

const float& GameObject::GetRadius() const
{
	return m_radius;
}

const int& GameObject::GetLives() const
{
	return m_lives;
}

void GameObject::SetFaceRotation(const Vector2& dir)
{
	m_facingDir = dir;
}

void GameObject::SetPosition(const Vector2& pos)
{
	m_pos = pos;
}

void GameObject::SetRadius(const float& rad)
{
	m_radius = rad;
}

void GameObject::SetLives(const int& lives)
{
	m_lives = lives;
}

