#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

const unsigned int WIND_WIDTH = 800;
const unsigned int WIND_HEIGHT = 600;
const unsigned int FRAME_RATE = 60;

void updateSprite(sf::Sprite &dvix_sprite, sf::Vector2f &speed)
{
    sf::Vector2f new_position = dvix_sprite.getPosition();

    // check if we arrived at the bound
    if (new_position.x <= 0 || new_position.x + dvix_sprite.getGlobalBounds().width >= WIND_WIDTH)
    {
        dvix_sprite.setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        speed.x *= -1;
    }
    if (new_position.y <= 0 || new_position.y + dvix_sprite.getGlobalBounds().height >= WIND_HEIGHT)
    {
        dvix_sprite.setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        speed.y *= -1;
    }

    new_position.x += speed.x;
    new_position.y += speed.y;

    dvix_sprite.setPosition(new_position);
}

int main()
{

    std::srand(std::time(nullptr));

    // Create a window
    sf::RenderWindow window(sf::VideoMode(WIND_WIDTH, WIND_HEIGHT), "SFML Window");
    window.setFramerateLimit(60);

    // load the texture
    sf::Texture dvix_texture;
    dvix_texture.loadFromFile("../ressources/dvix.png");

    // init the object
    sf::Sprite dvix_sprite;
    dvix_sprite.setColor(sf::Color::White);
    dvix_sprite.setTexture(dvix_texture);
    dvix_sprite.setPosition(WIND_WIDTH / 2, WIND_HEIGHT / 2);

    sf::Vector2f speed(FRAME_RATE / 15, FRAME_RATE / 15);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // compute and set new position
        updateSprite(dvix_sprite, speed);

        window.draw(dvix_sprite);
        window.display();
    }

    return 0;
}
