#pragma once
#include <set>
#include "Player.h"

enum class directions {
	up,
	down,
	left,
	right,
	none
};

class Collision {
public:
	std::vector<sf::FloatRect> walls;
	sf::RectangleShape diag1;
	bool stopLeft = false, stopRight = false, stopUp = false, stopDown = false;
	std::set<std::string> wallKeys;

	int findSide(sf::Vector2f norme);
	directions findDirection(sf::Vector2f norme);
	void findRestriction(sf::Vector2f diff);
	void addWall(sf::Sprite& sprite, std::string& key);
	sf::Vector2f applyRestriction(sf::Vector2f input);
	void Update(Player& player);
	void init();
	void draw(sf::RenderWindow& window);
};

//class Collision{
//public:
//	Collision(sf::RectangleShape& body);
//	void Move(float dx, float dy) { body.move(dx, dy); }
//	bool checkCollision(Collision& other, float push);
//	sf::Vector2f getPosition() { return body.getPosition(); };
//	sf::Vector2f getHalfSize() { return body.getSize() / 2.0f;}
//
//protected:
//	sf::RectangleShape body;
//};