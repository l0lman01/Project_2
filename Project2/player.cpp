#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

typedef sf::Vector2i vec2i;
using namespace sf;
using namespace std;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	anime(texture, imageCount, switchTime) {
	this->speed = speed;
	row = 0;
	isMoving = false;
	body.setSize(sf::Vector2f(50.f, 70.f));
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

void Player::Update(float deltaTime, bool attacking){

	sf::Vector2f velocity(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x = -speed * deltaTime;
		row = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x = speed * deltaTime;
		row = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y = -speed * deltaTime;
		row = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y = speed * deltaTime;
		row = 0;
	}


	if (velocity.x == 0.0f && velocity.y == 0.0f) {
		isMoving = false;
		anime.Update(row, deltaTime, 4, 4);
	}
	else{
			isMoving = true;
			anime.Update(row, deltaTime, 3, 6);
	}

	body.setTextureRect(anime.uvRect);
	body.move(velocity);
	playerSword.setPosition(body.getPosition());
}

void Player::drawPlayer(sf::RenderWindow& player, bool attacking){
	player.draw(body);
	if (attacking) {
		player.draw(playerSword);
	}
}