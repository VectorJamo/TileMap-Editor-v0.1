#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

#include "../utils/Rect.h"
#include "../graphics/Window.h"

struct TextureArea
{
	sf::Texture* texture;
	Rect textureRect;

	TextureArea();
	TextureArea(sf::Texture* texture, const Rect& rect);
};

class TileMap
{
private:
	Window* m_Window;

	int32_t** m_Map;
	int32_t m_WorldRows, m_WorldCols, m_TileSize;

	// If using 1 tile -> 1 texture
	std::unordered_map<uint8_t, sf::Texture*> m_TileIdentity;

	// If using texture atlases
	std::unordered_map<uint8_t, TextureArea> m_TileIdentityForAtlas;

private:
	void LoadMap(const std::string& path);
	void LogMap();

public:
	TileMap(Window* window, int32_t worldRows, int32_t worldCols, int32_t tileSize, const std::string& mapPath);
	~TileMap();

	// If using 1 tile -> 1 texture
	void SetTileIdentity(uint8_t tileNum, sf::Texture* texture);

	// If using texture atlases
	void SetTileIdentity(uint8_t tileNum, TextureArea croppedTexture);

	void Render();
	void Render(sf::Shader* shader);

	int32_t** GetMap() { return m_Map; }
};
