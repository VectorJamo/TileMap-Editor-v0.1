#pragma once
#include "framework/graphics/Window.h"
#include "framework/ui/Text.h"

class InputBox
{
private:
	sf::RectangleShape m_InputBox;
	int32_t m_OutlineThickness;
	sf::Color m_BgColor, m_TextColor, m_OutlineColor;

	Text* m_Text;
	uint32_t m_CharSize;

	bool m_IsActive; // When the user clicks on the input box

private:
	int32_t GetInputBoxHeight(sf::Font& font, int32_t charSize);
	void RepositionText();

public:
	InputBox(sf::Vector2f position, sf::Font& font, int32_t charSize, int32_t width, sf::Color bgColor, sf::Color textColor);
	~InputBox();

	void Update(float deltaTime);
	void Render(Window* window);

	void SetBackgroundColor(sf::Color color);
	void SetTextColor(sf::Color color);
	void SetOutline(int32_t outlineThickness, sf::Color outlineColor);

	inline bool IsActive() const { return m_IsActive; }
};

