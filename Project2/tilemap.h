#pragma once

class Tilemap {
public:
	sf::Sprite load_Level(sf::Texture& t);
private:
	std::vector<sf::Sprite> Tile;
};