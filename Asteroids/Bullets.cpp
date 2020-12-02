#include "Bullets.h"
#include "Application.h"
Bullets::Bullets(Application* app)
{
	m_app = app;
}

Bullets::~Bullets()
{
}

void Bullets::Update(float dt)
{
	m_pos.x += m_facingDir.x * m_speed;
	m_pos.y += m_facingDir.y * m_speed;

	
}



void Bullets::Draw()
{
	DrawCircle(m_pos.x, m_pos.y, 10, BLACK);
	DrawLine(m_pos.x, m_pos.y, m_pos.x + m_facingDir.x * 50, m_pos.y + m_facingDir.y * 50, RED);


}
