#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace AppTheme 
{
	static constexpr sf::Color BrightRed = { 240, 50, 50, 255 };
	static constexpr sf::Color DarkRed = { 180, 50, 50, 255 };
	static constexpr sf::Color PlainWhite = { 245, 245, 245, 255 };

	static constexpr sf::Color TextColorPrimary = BrightRed;
	static constexpr sf::Color TextColorSecondary = PlainWhite;
}