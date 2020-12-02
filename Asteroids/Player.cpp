#include "Player.h"
#include "Application.h"
Player::Player(Application* app)
{
	m_app = app;
	m_playerTexture = LoadTexture("./assets/AsteroidsShip.png");
	
}


Player::~Player()
{
}

void Player::Draw()
{
	float rot = atan2f( m_facingDir.y, m_facingDir.x) * (180.0f / PI);
	float tw = (float)m_playerTexture.width / 10;//Tile width
	float th = (float)m_playerTexture.height / 10;//Tileheight




	DrawTexturePro(m_playerTexture, 
		{ 0.0f, 0.0f, (float)m_playerTexture.width, (float)m_playerTexture.height }, 
		{ m_pos.x, m_pos.y, tw, th }, 
		{ tw * 0.5f, th * 0.5f }, rot, WHITE);

	DrawLine(m_pos.x, m_pos.y, m_pos.x + m_facingDir.x * 100, m_pos.y + m_facingDir.y * 100, BLACK);
}

void Player::Update(float dt)
{
	

	//Getting keys wasd for movement
	if (IsKeyDown(KEY_W))//Up
		m_pos.y-= m_speed;
	if (IsKeyDown(KEY_S))//Down
		m_pos.y+= m_speed;
	if (IsKeyDown(KEY_A))//Left
		m_pos.x-= m_speed;
	if (IsKeyDown(KEY_D))//Right
		m_pos.x+= m_speed;


	Vector2 mousePos = { GetMouseX(), GetMouseY() };
	m_facingDir = Vector2Normalize({ mousePos.x - m_pos.x, mousePos.y - m_pos.y });
}
