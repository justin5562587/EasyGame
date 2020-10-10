//
// Created by justin on 2020/10/10.
//
#include "../include/Game.h"

Game::Game() : _window(sf::VideoMode(1000, 1000), "Test SFML"), _player() {

}

void Game::run(int minimum_frame_per_seconds) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);
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
    _window.draw(_player.getTriangle());
    _window.display();
}



