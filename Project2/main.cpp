#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML Works");
    sf::RectangleShape entity(sf::Vector2f(100.f, 100.f));
    Texture texture;
    Texture maptextur;
    texture.loadFromFile("ghost.png");
    Sprite sprite;
    Tilemap T;
    maptextur.loadFromFile("foresttiles2-t.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();

            //azerty
            switch (event.key.code) {
                //Haut
            case sf::Keyboard::Z:
                entity.move(0.f, -2.f);
                break;
                //Down
            case sf::Keyboard::S:
                entity.move(0.f, 2.f);
                break;
                //Droite
            case sf::Keyboard::D:
                entity.move(2.f, 0.f);
                break;
                //Gauche
            case sf::Keyboard::Q:
                entity.move(-2.f, 0.f);
                break;
            }
        }
        window.clear();

        //window.draw(shape);
        //window.draw(sprite);
        window.draw(T.load_Level(maptextur));
        window.draw(entity);
        window.display();
    }
    return 0;
}