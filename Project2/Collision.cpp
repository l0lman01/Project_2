#include "SFML/Graphics.hpp"
#include <string>
#include "Collision.h"

//Collision::Collision(sf::RectangleShape& body) :
//	body(body){
//
//}
//
//
//bool Collision::checkCollision(Collision& other, float push)
//{
//	sf::Vector2f otherPosition = other.getPosition();
//	sf::Vector2f otherHalfSize = other.getHalfSize();
//	sf::Vector2f thisPosition = other.getPosition();
//	sf::Vector2f thisHalfSize = other.getHalfSize();
//
//	float delta;
//
//
//	return false;
//}

std::set<std::string> wallKeys = {
	"FL",
	"PL",
	"R1",
	"R2",
	"R3",
	"R4",
	"S2",
	"GS",
	"RH",
	"RV",
};

int Collision::findSide(sf::Vector2f norme)
{
	if (norme.x > 0) {
		if (norme.y > 0)
			return 3;
		else
			return 0;
	}
	else {
		if (norme.y > 0)
			return 2;
		else
			return 1;
	}
}

directions Collision::findDirection(sf::Vector2f norme){
	auto side = findSide(norme);
	bool yLarge = abs(norme.y) > abs(norme.x);
	switch (side) {
	case 0:
		if (yLarge)
			return directions::up;
		else
			return directions::right;
	case 1:
		if (yLarge)
			return directions::up;
		else
			return directions::left;
	case 2:
		if (yLarge)
			return directions::down;
		else
			return directions::left;
	case 3:
		if (yLarge)
			return directions::down;
		else
			return directions::right;
	default:
		return directions::none;
	}
}

void Collision::findRestriction(sf::Vector2f diff){
	auto dir = findDirection(diff);
	switch (dir) {
	case directions::down:
		stopDown = true;
		break;
	case directions::up:
		stopDown = true;
		break;
	case directions::left:
		stopDown = true;
		break;
	case directions::right:
		stopDown = true;
		break;
	}
}

void Collision::addWall(sf::Sprite& sprite, std::string& key){
	if (!wallKeys.count(key)) {
		walls.push_back(sprite.getGlobalBounds());
	}
}

sf::Vector2f Collision::applyRestriction(sf::Vector2f input) {
	if (input.x > 0 && stopLeft)
		input.x = 0;
	if (input.x < 0 && stopRight)
		input.x = 0;
	if (input.y > 0 && stopDown)
		input.y = 0;
	if (input.y < 0 && stopUp)
		input.y = 0;
	return input;
}

void Collision::Update(Player& player){
	auto playerAABB = player.body.getGlobalBounds();
	std::vector<sf::FloatRect> collided;
	for (auto& wall : walls) {
		if (playerAABB.intersects(wall))
			collided.push_back(wall);
	}

	sf::Vector2f moyenne;
	stopDown = stopLeft = stopRight = stopUp = false;
	for (auto& a : collided) {
		sf::Vector2f AABBCentre = sf::Vector2f(a.left, a.top) + 1.f * sf::Vector2f(a.width, a.height);
		moyenne += AABBCentre;
		sf::Vector2f diff = AABBCentre - player.body.getPosition();
		findRestriction(diff);
	}
	moyenne /= float(collided.size());
	diag1.setPosition(moyenne);
}

void Collision::init(){
	diag1 = sf::RectangleShape({ 10,10 });
	diag1.setOrigin(1.f * diag1.getSize());
}

void Collision::draw(sf::RenderWindow& window){
	window.draw(diag1);
}