#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

    sf::Window window(sf::VideoMode(500, 500), "My Window");

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
