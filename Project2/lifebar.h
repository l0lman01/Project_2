#pragma once

class Lifebar{
public:
	
	Lifebar();
	void Update(sf::RectangleShape body);
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape LifebarBack;
	sf::RectangleShape Life;
};