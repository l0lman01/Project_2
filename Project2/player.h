#pragma once
#include "Animation.h"
#include "Weapon.h"

class Player {
public:
	int lifePoints;
	sf::Vector2i movement;
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void treat_key_release(sf::Keyboard::Key key_code);
	void treat_key_press(sf::Keyboard::Key key_code);
	void Update(float deltaTime, bool attacking);
	void drawPlayer(sf::RenderWindow& player, bool attacking);

protected:
	float speed;
	int row;
	bool isMoving;
	sf::RectangleShape body;
	sf::Texture player_texture;
	sf::Sprite player_sprite;
	Animation anime;
private:
	Weapon playerSword;
};