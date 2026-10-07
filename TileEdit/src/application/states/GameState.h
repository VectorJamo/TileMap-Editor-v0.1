#pragma once

#include <iostream>
#include <memory>

#include "framework/assets/AssetManager.h"
#include "framework/states/StateManager.h"
#include "framework/tilemap/TileMap.h"

#include "framework/ui/InputBox.h"

class GameState : public StateManager
{
private:
    std::unique_ptr<AssetManager> m_AssetManager;

	std::unique_ptr<InputBox> m_InputBox;
    	
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

