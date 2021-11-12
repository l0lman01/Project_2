#include <set>
#include <string>
#include "SFML/Graphics.hpp"
#include "Collision.h"



Collision::Collision(sf::RectangleShape& body) :
	body(body){

}


bool Collision::checkCollision(Collision& other, float push)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = other.getPosition();
	sf::Vector2f thisHalfSize = other.getHalfSize();

	float delta


	return false;
}
