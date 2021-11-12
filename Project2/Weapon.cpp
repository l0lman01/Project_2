#include <SFML/Graphics.hpp>
#include "Weapon.h"

Weapon::Weapon(){
	weaponTexture.loadFromFile("sword.png");
	weapon = sf::Sprite(weaponTexture);

	weapon.setOrigin(sf::Vector2f(0.5f, 5.0f));
}

void Weapon::drawWeapon(sf::RenderWindow& weapon){
	weapon.draw(weaponBox);
}