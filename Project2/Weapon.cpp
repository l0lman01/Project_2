#include <SFML/Graphics.hpp>
#include <iostream>
#include "Weapon.h"

Weapon::Weapon(){
	weaponTexture.loadFromFile("sword.png");
	weapon = sf::Sprite(weaponTexture);
	weapon.setOrigin(sf::Vector2f(0.5f, 5.0f));
	weapon.setPosition(sf::Vector2f());
}

void Weapon::Attack(){
	startAngle = (angle - 45 + 360) % 360;
	weapon.setRotation(startAngle);
}

void Weapon::setAngle(int deg) {
	angle = deg;
}

void Weapon::Update(float delta, bool attacking){
	if (elapsedTime < 40)
	{
		angle += 4;
		elapsedTime += delta;
		weapon.setRotation(angle);
	}
	else
	{
		elapsedTime = 0;
	}
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform *= getTransform();
	target.draw(weapon, states);
}

//void Weapon::drawWeapon(sf::RenderWindow& weapon){
//	weapon.draw(weaponBox);
//}