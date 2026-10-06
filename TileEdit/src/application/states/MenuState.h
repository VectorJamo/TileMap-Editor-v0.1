#pragma once
#include <memory>

#include "framework/states/StateManager.h"

#include "framework/ui/Text.h"
#include "framework/ui/Button.h"
#include "framework/ui/Frame.h"

#include "framework/assets/AssetManager.h"

class MenuState : public StateManager
{
private:
	// Assets
	std::unique_ptr<AssetManager> m_Assets;

	// UI
	std::unique_ptr<Frame> m_Frame;

	std::unique_ptr<Text> m_TitleText;
	std::unique_ptr<Button> m_StartButton, m_QuitButton;

private:
	void LoadAssets();

public:
	MenuState(Window* window);
	~MenuState();

	void Update(float deltaTime) override;
	void Render() override;
};

