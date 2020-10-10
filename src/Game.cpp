//
// Created by justin on 2020/10/10.
//
#include "../include/Game.h"

Game::Game() : _window(sf::VideoMode(1000, 1000), "02_Game_Archi"), _player(150) {

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
//        else if (event.type == sf::Event::KeyPressed) {
//            if (event.key.code == sf::Keyboard::Escape) {
//                _window.close();
//            } else if (event.key.code == sf::Keyboard::Up) {
//                _player.isMoving = true;
//            } else if (event.key.code == sf::Keyboard::Left) {
//                _player.rotation = -1;
//            } else if (event.key.code == sf::Keyboard::Right) {
//                _player.rotation = 1;
//            }
//        } else if (event.type == sf::Event::KeyReleased) {
//            if(event.key.code == sf::Keyboard::Up)
//                _player.isMoving = false;
//            else if (event.key.code == sf::Keyboard::Left)
//                _player.rotation = 0;
//            else if (event.key.code == sf::Keyboard::Right)
//                _player.rotation = 0;
//        }
    }
}

void Game::update(sf::Time deltaTime) {


}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}



