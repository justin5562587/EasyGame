//
// Created by justin on 2020/10/10.
//
#include "../include/Game.h"

Game::Game() : _window(sf::VideoMode(400, 500), "Test window"), _player() {
    _player.setPosition(10, 20);
}

void Game::run(int minimum_frame_per_second) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_second);

    while (_window.isOpen()) {
        processEvents();
        timeSinceLastUpdate = clock.restart();
        if (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            _window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _window.close();
            }
        }
    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime) {
    _player.update(deltaTime);
}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}
