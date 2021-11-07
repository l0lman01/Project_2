#pragma once

class Player {
public:
	int lifePoints;
	Player();
	void drawPlayer(sf::RenderWindow& player);
protected:
	sf::Texture player_texture;
	sf::Sprite player_sprite;
};