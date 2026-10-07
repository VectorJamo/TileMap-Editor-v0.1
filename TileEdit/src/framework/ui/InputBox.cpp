#include "InputBox.h"
#include "framework/input/Input.h"

int32_t InputBox::GetInputBoxHeight(sf::Font& font, int32_t charSize)
{
	uint32_t height = font.getLineSpacing(charSize);
	return height;
}

void InputBox::RepositionText()
{
	sf::Vector2f textPosition = { m_InputBox.getPosition().x + m_CharSize / 2.0f, m_InputBox.getPosition().x + m_CharSize / 2.0f };
	m_Text->SetPosition(textPosition);
}

InputBox::InputBox(sf::Vector2f position, sf::Font& font, int32_t charSize, int32_t width, sf::Color bgColor, sf::Color textColor)
	:m_OutlineThickness(0), m_BgColor(bgColor), m_TextColor(textColor), m_OutlineColor(bgColor), m_Text(nullptr), m_CharSize(charSize), m_IsActive(false)
{
	m_InputBox.setPosition(position);
	m_InputBox.setSize(sf::Vector2f(width, GetInputBoxHeight(font, charSize)));
	m_InputBox.setFillColor(m_BgColor);
	m_InputBox.setOutlineThickness(m_OutlineThickness);
	m_InputBox.setOutlineColor(m_OutlineColor);

	m_Text = new Text(font);
	m_Text->SetCharacterSize(charSize);
	m_Text->SetFillColor(m_TextColor);
	m_Text->SetPosition(position);
}

InputBox::~InputBox()
{
	delete m_Text;
}

void InputBox::Update(float deltaTime)
{
	sf::Vector2i mPos = Input::GetMousePosition();

	if (mPos.x > m_InputBox.getPosition().x && mPos.x < m_InputBox.getPosition().x + m_InputBox.getSize().x
		&& mPos.y > m_InputBox.getPosition().y && mPos.y < m_InputBox.getPosition().y + m_InputBox.getSize().y)
	{
		if (Input::IsMouseButtonPressed(MouseButton::Left))
		{
			m_IsActive = true;
		}
	}
	else {
		if (Input::IsMouseButtonPressed(MouseButton::Left))
		{
			m_IsActive = false;
		}
	}

	if (m_IsActive)
	{
		// Take the input
		if (Input::TypedChar.has_value())
		{
			char c = (char)Input::TypedChar.value();
				
			std::string currentString = m_Text->GetString();
			std::string newString;

			// Backspace
			if (c == 8 && currentString.length() > 0)
			{
				currentString.pop_back();
				m_Text->SetString(currentString);
				RepositionText();
			}
			else if((m_Text->GetWidth() + m_CharSize*1.5f) < m_InputBox.getSize().x) { // Add a char size*1.5f to prevent overflowing
				if (c == 13)
				{
					std::cout << "Enter typed." << std::endl;
					return;
				}
				else {
					std::string newString = currentString + std::string{ c };
					m_Text->SetString(newString);
					RepositionText();
				}
			}
		}
	}
}

void InputBox::Render(Window* window)
{
	window->GetWindowInstance()->draw(m_InputBox);
	m_Text->Render(window);
}

void InputBox::SetBackgroundColor(sf::Color color)
{
	m_BgColor = color;
	m_InputBox.setFillColor(color);
}

void InputBox::SetTextColor(sf::Color color)
{
	m_TextColor = color;
	m_Text->SetFillColor(color);
}

void InputBox::SetOutline(int32_t outlineThickness, sf::Color outlineColor)
{
	m_OutlineThickness = outlineThickness;
	m_OutlineColor = outlineColor;

	m_InputBox.setOutlineThickness(outlineThickness);
	m_InputBox.setOutlineColor(outlineColor);
}
