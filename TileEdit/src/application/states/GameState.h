#pragma once

#include <iostream>
#include <memory>

#include "framework/assets/AssetManager.h"
#include "framework/states/StateManager.h"
#include "framework/tilemap/TileMap.h"

class GameState : public StateManager
{
private:
    std::unique_ptr<AssetManager> m_AssetManager;
    	
private:
	void LoadAssets();

	void InitEntities();
	void InitObjects();
	void InitUI();

public:
	GameState(Window* window);
	~GameState();

	void Update(float deltaTime) override;
	void Render() override;
};

