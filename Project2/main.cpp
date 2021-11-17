#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Tilemap.h"
#include "Collision.h"
#include "Lifebar.h"
#include "Player.h"
#include "Enemy.h"

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML Works");

    Tilemap map;

    Collision collision;

    Texture playerTexture;
    playerTexture.loadFromFile("characters.png");
    Player player(&playerTexture, Vector2u(12, 8), 0.25f, 100.0f);
    bool attacking = false;

    Texture enemyTexture;
    enemyTexture.loadFromFile("characters.png");
    Enemy enemy(&enemyTexture, Vector2u(12, 8), 0.3f, 100.0f);

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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                    attacking = true;
                }
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

        //Afficher la map
        map.drawMap(window); 
        
        //Update
        collision.Update(player);
        player.playerHP.Update(player.body);
        player.Update(deltaTime, attacking);
        enemy.Update(deltaTime);

        //Draw
        collision.draw(window);
        player.playerHP.draw(window);
        player.drawPlayer(window, attacking);
        enemy.drawEnemy(window);

        window.display();
    }
    return 0;
}