#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include "Player.h"
#include "Animation.h"
#include "lifebar.h"
#include "Enemy.h"

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML Works");

    Tilemap map;
    Texture playerTexture;
    playerTexture.loadFromFile("hero.png");
    Player player(&playerTexture, Vector2u(4, 4), 0.25f, 100.0f);

    Texture enemyTexture;
    enemyTexture.loadFromFile("characters.png");
    Enemy enemy(&enemyTexture, Vector2u(8, 9), 0.3f, 100.0f);

    float deltaTime = 10.f;
    Clock clock;

    map.load_level();


    while (window.isOpen()){
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
            case sf::Event::KeyPressed:
                player.treat_key_press(event.key.code);
                break;
            case sf::Event::KeyReleased:
                player.treat_key_release(event.key.code);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }


        }

        
        window.clear();

        map.drawMap(window); //Afficher la map
        
        //Update
        player.Update(deltaTime);
        enemy.Update(deltaTime);

        //Draw
        player.drawPlayer(window);
        enemy.drawEnemy(window);

        window.display();
    }
    return 0;
}