#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    sf::Window window(sf::VideoMode(500, 500), "My Window");

//    sf::Texture texture;
//    if (!texture.loadFromFile("../sfml_test.jpeg")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite sprite;
//    sprite.setTexture(texture);

    sf::Image image;
    if (!image.loadFromFile("../sfml_test.jpeg")) {
        return EXIT_FAILURE;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    return 0;
}
