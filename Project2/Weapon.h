#pragma once

class Weapon: public sf::Drawable, public sf::Transformable{
public:
	Weapon();
	void drawWeapon(sf::RenderWindow& weapon);
protected:
	sf::RectangleShape weaponBox;
	sf::Sprite weapon;
	sf::Texture weaponTexture;
};