#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

    // create main window
    sf::Window window(sf::VideoMode(800, 600), "My Window");

    // load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile("./sfml_test.jpeg")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite sprite(texture);

    sf::Text text("Hello SFML");

    while (window.isOpen()) {
        // process event
        sf::Event event;
        while (window.pollEvent(event)) {

            // close window exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.display();
    }

    return EXIT_SUCCESS;

    return 0;
}
