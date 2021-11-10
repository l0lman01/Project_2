#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include "Animation.h"
#include "lifebar.h"

using namespace sf;

int main() {
	Texture enemyTexture;
	enemyTexture.loadFromFile("characters.png");
	Sprite enemySprite;
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(3, 3);
	enemySprite.setTextureRect(IntRect(Vector2i(0, 48), Vector2i(16, 16)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(enemySprite);
        window.display();
    }

    return 0;
};