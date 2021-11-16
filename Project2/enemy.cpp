#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include "Animation.h"
#include "lifebar.h"
#include "Enemy.h"

using namespace sf;

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed): // initialisation g�n�rale
		anime(texture, imageCount, switchTime) {
		this->speed = speed;
		row = 6;
		isMoving = false;
		body.setSize(sf::Vector2f(100.f, 100.f));
		body.setPosition(100.f, 100.f);
		body.setTexture(texture);
};

void Enemy::drawEnemy(sf::RenderWindow& Enemy) { // affichage de l'ennemi
	Enemy.draw(body);
};

Vector2f interp2d(Vector2f start, Vector2f end, float coef) {
	return coef * (end - start) + start;
}

void Enemy::Update(float deltaTime) { // d�placement de l'ennemi : la liste correspond aux points du chemin qu'il va suivre
	Vector2f chemin;
	std::vector<Vector2f> data = {  // les points ont �t� doubl�s pour faire la pause � chaque fin de d�placement
		Vector2f(390,20),
		Vector2f(390,20),
		Vector2f(435,20),
		Vector2f(435,20),
		Vector2f(435,70),
		Vector2f(435,70),
		Vector2f(390,70),
		Vector2f(390,70),
		Vector2f(390,20),
		Vector2f(390,20)
	};

	accum += deltaTime; // au niveau de la pause : pas besoin d'une clock avec getelapsedtime, accum qui est un chronom�tre s'en charge tout seul

	if (accum > 1)
	{
		accum = 0;
		segment = segment + 1;

		if (segment >= 8)
		{
			segment = 0;
		}

		switch (segment) { // le switch sert � l'animation, le changement de row correspond � la texture � utiliser dans characters.png
		case 0:
		case 1: // les cases sont doubl�s comme les points du vecteur
			row = 6;
			break;
		case 2:
		case 3:
			row = 4;
			break;
		case 4:
		case 5:
			row = 5;
			break;
		case 6:
		case 7:
			row = 7;
			break;
		}
	}

	Vector2f mouvement = interp2d(data[segment], data[segment+1], accum);
	body.setPosition(mouvement); // on enclenche le mouvement

	body.setTextureRect(anime.uvRect);
	anime.Update(row, deltaTime, 0, 2); // on anime
};