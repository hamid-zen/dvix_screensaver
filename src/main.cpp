#include <SFML/Graphics.hpp>

const unsigned int WIND_WIDTH = 800;
const unsigned int WIND_HEIGHT = 600;

sf::Vector2f updatePosition(sf::Vector2f const &current_position, sf::Vector2u const &object_size, float &speed) {
    sf::Vector2f new_position = current_position;

    // check if we arrived at the bound horizontally
    if (new_position.x <= 0 || new_position.x + object_size.x >= WIND_WIDTH) {
        speed *= -1;
    }
    new_position.x += speed;
    return new_position;
}

int main() {

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
    dvix_sprite.setPosition(WIND_WIDTH/2, WIND_HEIGHT/2);

    float speed = 5;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // compute and set new position
        sf::Vector2f new_position = updatePosition(dvix_sprite.getPosition(), dvix_texture.getSize(), speed);
        dvix_sprite.setPosition(new_position);

        window.draw(dvix_sprite);
        window.display();
    }

    return 0;
}
