//
// Created by justin on 2020/10/10.
//
#include "../include/Game.h"
#include "../include/TileMap.h"
#include <stdexcept>

Game::Game() : _window(sf::VideoMode(1000, 1000), "Test SFML"), _player() {

}

void Game::run(int minimum_frame_per_seconds) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);

    // define the level with an array of tile indices
    const int level[] =
            {
                    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
                    0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
                    2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
                    0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
            };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 8)) {
        throw std::runtime_error("load tile picture error");
    }

    while (_window.isOpen()) {
        processEvent();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvent() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
    }
}

void Game::update(sf::Time deltaTime) {


}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}



