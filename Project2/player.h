#pragma once
#include "Animation.h"
#include "Weapon.h"
#include"Lifebar.h"


class Player: public sf::Transformable {
public:
	int lifePoints;
	sf::Vector2i movement;
	sf::RectangleShape body;
	Lifebar playerHP;
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void treat_key_release(sf::Keyboard::Key key_code);
	void treat_key_press(sf::Keyboard::Key key_code);
	void Update(float deltaTime, bool attacking);
	void drawPlayer(sf::RenderWindow& player, bool attacking);
	
protected:
	float speed;
	int row;
	bool isMoving;
	Animation anime;
private:
	Weapon playerSword;
};