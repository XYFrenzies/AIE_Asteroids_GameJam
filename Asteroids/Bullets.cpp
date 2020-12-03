#include "Bullets.h"
#include "Application.h"
Bullets::Bullets(Application* app)
{
	m_app = app;
	SetRadius(10);
}

Bullets::~Bullets()
{
}

void Bullets::Update(float dt)
{
	m_pos.x += m_facingDir.x * m_bulletSpeed;
	m_pos.y += m_facingDir.y * m_bulletSpeed;

	
}



void Bullets::Draw()
{
	//DrawCircle(m_pos.x, m_pos.y, m_radius, { 255, 0, 0, 100 });
	DrawCircle(m_pos.x, m_pos.y, m_radius, YELLOW);
	//DrawLine(m_pos.x, m_pos.y, m_pos.x + m_facingDir.x * 50, m_pos.y + m_facingDir.y * 50, RED);

}
