#pragma once
#include "Animation.h"

class Player {
public:
	int lifePoints;
	sf::Vector2i movement;
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void Update(float deltaTime);
	void drawPlayer(sf::RenderWindow& player);

protected:
	float speed;
	int row;
	bool isMoving;
	sf::RectangleShape body;
	sf::Texture player_texture;
	sf::Sprite player_sprite;
	Animation anime;
};