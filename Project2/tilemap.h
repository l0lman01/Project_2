#pragma once
#include "Collision.h"

class Tilemap {
public:
	void load_level();
	void drawMap(sf::RenderWindow& map);
	std::vector<sf::Sprite> Tiles;
	std::vector<sf::Sprite> groundTiles;
protected:
	sf::Texture tiles_texture;
	Collision collision;
};