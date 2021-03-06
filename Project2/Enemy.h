#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
public:
	int lifePoints;
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void Update(float deltaTime);
	void drawEnemy(sf::RenderWindow& player);

	float speed;
	int row;
	bool isMoving;
	sf::RectangleShape body;
	Animation anime;

	std::vector<Vector2f> chemin;

	int segment = 0;
	float accum = 0;

private:

};