#include <SFML/Graphics.hpp>
#include <iostream>
#include "Lifebar.h"

Lifebar::Lifebar(){
	LifebarBack.setSize(sf::Vector2f(100.f, 20.f));
	LifebarBack.setFillColor(sf::Color::Black);
	
	Life.setSize(sf::Vector2f(100.f, 20.f));
	Life.setFillColor(sf::Color(250, 20, 20, 200));
}

void Lifebar::Update(sf::RectangleShape body){
	
	LifebarBack.setPosition(body.getPosition().x - 25.f, body.getPosition().y - 25.f);
	Life.setPosition(body.getPosition().x - 25.f, body.getPosition().y - 25.f);
}

void Lifebar::draw(sf::RenderWindow& window){
	window.draw(LifebarBack);
	window.draw(Life);
}