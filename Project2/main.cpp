#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include "Player.h"
#include "Animation.h"
#include "lifebar.h"

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML Works");

    Tilemap map;
    Texture playerTexture;
    playerTexture.loadFromFile("characters.png");
    Player player(&playerTexture, Vector2u(12, 8), 0.5f, 100.0f);

    float deltaTime = 0.5f;
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
        player.Update(deltaTime);
        player.drawPlayer(window);
        window.display();
    }
    return 0;
}