#include "GameState.h"
#include <iostream>

#include "../tilemap/MapConstants.h"

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
    
}

void GameState::InitEntities()
{
}

void GameState::InitObjects()
{
}

void GameState::InitUI()
{
}


GameState::~GameState()
{
}

void GameState::Update(float deltaTime)
{
}

void GameState::Render()
{
}
