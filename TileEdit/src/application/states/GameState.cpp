#include "GameState.h"
#include <iostream>

#include "../tilemap/MapConstants.h"
#include "framework/input/Input.h"

GameState::GameState(Window* window)
	:StateManager(window)
{
	LoadAssets();
    
	InitEntities();
	InitObjects();
	InitUI();

	std::cout << "GameState Initialized!" << std::endl;
}

void GameState::LoadAssets()
{
    m_AssetManager = std::make_unique<AssetManager>();
	m_AssetManager->LoadFont(AssetManager::GetFromFontDir("8-bit/8-bit-pusab.ttf"));
}

void GameState::InitEntities()
{
}

void GameState::InitObjects()
{
}

void GameState::InitUI()
{
	m_InputBox = std::make_unique<InputBox>(sf::Vector2f(100.0f, 100.0f), m_AssetManager->GetFont(AssetManager::GetFromFontDir("8-bit/8-bit-pusab.ttf")), 18, 100, 
		sf::Color(50, 50, 50, 255), sf::Color(255, 255, 255, 255));
	m_InputBox->SetOutline(1, { 100, 100, 100, 255 });
}

GameState::~GameState()
{
}

void GameState::Update(float deltaTime)
{
	m_InputBox->Update(deltaTime);
}

void GameState::Render()
{
	m_InputBox->Render(GetWindow());
}
