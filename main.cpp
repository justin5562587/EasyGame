#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My Window");

    sf::Texture texture;
    if (!texture.loadFromFile("../sfml_test.jpeg")) {
        std::cout << "error" << std::endl;
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
//    while (window.isOpen()) {
//        sf::Event event;
//
//        while (window.pollEvent(event)) {
//
//            switch (event.type) {
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//                case sf::Event::KeyPressed:
//                    if (event.key.code == sf::Keyboard::Escape) {
//                        std::cout << "the escape key was pressed" << std::endl;
//                        std::cout << "control:" << event.key.control << std::endl;
//                        std::cout << "alt:" << event.key.alt << std::endl;
//                        std::cout << "shift:" << event.key.shift << std::endl;
//                        std::cout << "system:" << event.key.system << std::endl;
//                    }
//                    break;
//                case sf::Event::MouseButtonPressed:
//                    if (event.mouseButton.button == sf::Mouse::Left) {
//                        std::cout << "left mouse clicked" << std::endl;
//                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//                    }
//                    break;
//                default:
//                    break;
//            }
//        }
//
//        window.display();
//    }

    return EXIT_SUCCESS;
}
