#pragma once

class Weapon : public sf::Drawable, public sf::Transformable {
public:
	Weapon();
	void Attack();
	void setAngle(int deg);
	void Update(float delta, bool attacking);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	int angle;
	int startAngle;
	float elapsedTime = 0;
	float ratio;
	sf::RectangleShape weaponBox;
	sf::Sprite weapon;
	sf::Texture weaponTexture;
};