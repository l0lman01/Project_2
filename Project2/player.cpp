#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.h"

using namespace sf;

Player::Player() {
	player_texture.loadFromFile("ghost.png");
	player_sprite = Sprite(player_texture);
}

void Player::drawPlayer(sf::RenderWindow& player){
	player.draw(player_sprite);
}
