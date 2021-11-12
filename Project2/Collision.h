#pragma once

class Collision{
public:
	Collision(sf::RectangleShape& body);
	void Move(float dx, float dy) { body.move(dx, dy); }
	bool checkCollision(Collision& other, float push);
	sf::Vector2f getPosition() { return body.getPosition(); };
	sf::Vector2f getHalfSize() { return body.getSize() / 2.0f;}

protected:
	sf::RectangleShape body;
};