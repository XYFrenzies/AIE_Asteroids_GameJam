#include "Application.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

Application::Application() : m_screenWidth(), m_screenHeight()
{
}

Application::~Application()
{
}

void Application::Startup()
{
	m_screenWidth = 800;
	m_screenHeight = 450;

	InitWindow(m_screenWidth, m_screenHeight, "Asteroids Game");
	SetTargetFPS(60);
}

void Application::Run()
{
    // Main game loop
    Load();
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float dt = GetFrameTime();
        if (dt > 1.0f / 12.0f)
            dt = 1.0f / 12.0f;
        Update(dt);
        Draw();
    }
    Unload();
}

void Application::Update(float dt)
{
    m_player->Update(dt);

    if (IsKeyPressed(KEY_SPACE))
    {
        Bullets* newBull = new Bullets(this);
        newBull->SetFaceRotation(GetPlayer()->GetFaceRotation());
        newBull->SetPosition(GetPlayer()->GetPosition());
        m_bullets.push_back(newBull);
    }
    
    for (auto bullet : m_bullets)
        bullet->Update(dt);
}

void Application::Draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    m_player->Draw();

    for (auto bullet : m_bullets)
        bullet->Draw();

    EndDrawing();
}

void Application::Load()
{
    m_player = new Player(this);
    m_player->SetPosition({ m_screenWidth * 0.25f, m_screenHeight * 0.25f });
}

void Application::Unload()
{
    delete m_player;
    m_player = nullptr;

    for (auto bullet : m_bullets)
        delete bullet;

    m_bullets.clear();
}
Player* Application::GetPlayer()//Gets the values of player
{
    return m_player;
}
std::list<Bullets*>& Application::GetBullets()//Gets the values of player
{
    return m_bullets;
}

