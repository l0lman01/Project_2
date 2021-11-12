#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include "Animation.h"
#include "lifebar.h"
#include "Enemy.h"

using namespace sf;

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
		anime(texture, imageCount, switchTime) {
		this->speed = speed;
		row = 4;
		isMoving = false;
		body.setSize(sf::Vector2f(100.f, 100.f));
		body.setPosition(100.f, 100.f);
		body.setTexture(texture);
};

void Enemy::drawEnemy(sf::RenderWindow& Enemy) {
	Enemy.draw(body);
};

Vector2f interp2d(Vector2f start, Vector2f end, float coef) {
	return coef * (end - start) + start;
}

void Enemy::Update(float deltaTime) {
	Vector2f chemin;
	std::vector<Vector2f> data = { Vector2f(390,20), Vector2f(435,20), Vector2f(435,70), Vector2f(390,70) };

	accum += deltaTime;

	if (accum > 1)
	{
		accum = 0;
		segment = segment + 1;
	}

	if (segment >= 3)
	{
		segment = 0;
	}

	Vector2f mouvement = interp2d(data[segment], data[segment+1], accum);
	body.setPosition(mouvement);

	body.setTextureRect(anime.uvRect);
	anime.Update(row, deltaTime, 0, 3);
};