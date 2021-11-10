#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"

typedef sf::Vector2i vec2i;
using namespace sf;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	anime(texture, imageCount, switchTime) {
	this->speed = speed;
	row = 0;
	isMoving = false;
	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setPosition(100.f, 100.f);
	body.setTexture(texture);


}
void Player::treat_key_release(Keyboard::Key key_code){
	switch (key_code) {
	case Keyboard::W:
	case Keyboard::S:
	case Keyboard::Z:
		movement.y = 0;
		break;
	case Keyboard::A:
	case Keyboard::D:
	case Keyboard::Q:
		movement.x = 0;
		break;
	}
}
void Player::treat_key_press(Keyboard::Key key_code){
	switch (key_code) {
	case Keyboard::W:
	case Keyboard::Z:
		movement += vec2i(0, -1);
		break;
	case Keyboard::A:
	case Keyboard::Q:
		movement += vec2i(-1, 0);
		break;
	case Keyboard::S:
		movement += vec2i(0, 1);
		break;
	case Keyboard::D:
		movement += vec2i(1, 0);
		break;
	}
}


void Player::Update(float deltaTime){
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		movement.x = -speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x = speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		movement.y = -speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y = speed * deltaTime;

	if (movement.x == 0.0f && movement.y == 0.0f) {
		row = 1;
		isMoving = false;
	}
	else{
		row = 2;
		if (movement.y > 0.0f || movement.x > 0.0f) {
			isMoving = true;
		}
		anime.Update(row, deltaTime, isMoving);
		body.setTextureRect(anime.uvRect);
		body.move(movement);
	}
}

void Player::drawPlayer(sf::RenderWindow& player){
	player.draw(body);
}