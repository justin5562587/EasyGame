//
// Created by justin on 2020/10/10.
//
#include "../include/Game.h"

Game::Game() : _window(sf::VideoMode(400, 500), "Test window"), _player(100) {
    _player.setFillColor(sf::Color::Blue);
    _player.setPosition(10, 20);
}

void Game::run() {
    while (_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    _window.close();
                }
                break;
            default:
                break;
        }

    }
}

void Game::update() {}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}
