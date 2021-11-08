#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include"player.h"

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML Works");
    sf:RectangleShape player(sf::Vector2f(100.f, 100.f));
    Tilemap map;
    Player playericon;
    Texture playerSprite;
    playerSprite.loadFromFile("ghost.png");
    player.setTexture(&playerSprite);
    map.load_level();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //azerty
            switch (event.key.code) {
                //Haut
            case sf::Keyboard::Z:
                player.move(0.f, -2.f);
                break;
                //Down
            case sf::Keyboard::S:
                player.move(0.f, 2.f);
                break;
                //Droite
            case sf::Keyboard::D:
                player.move(2.f, 0.f);
                break;
                //Gauche
            case sf::Keyboard::Q:
                player.move(-2.f, 0.f);
                break;
            }
        }
        window.clear();

        map.drawMap(window);
        window.draw(player);
        playericon.drawPlayer(window);
        window.display();
    }
    return 0;
}