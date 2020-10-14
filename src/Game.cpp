//
// Created by justin on 2020/10/10.
//
#include "../include/Game.h"

Game::Game() : _window(sf::VideoMode(400, 500), "Test window"), _player(100) {
    _player.setFillColor(sf::Color::Blue);
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

        switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    _window.close();
                } else if (event.key.code == sf::Keyboard::Up) {
                    _player.isMoving = true;
                } else if (event.key.code == sf::Keyboard::Down) {
                    _player.isMoving = false;
                } else if (event.key.code == sf::Keyboard::Left) {
                    _player.rotation = -1;
                } else if (event.key.code == sf::Keyboard::Right) {
                    _player.rotation = 1;
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Up) {
                    _player.isMoving = false;
                } else if (event.key.code == sf::Keyboard::Left) {
                    _player.rotation = -1;
                } else if (event.key.code == sf::Keyboard::Right) {
                    _player.rotation = 1;
                }
                break;
            default:
                break;
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
