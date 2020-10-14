//
// Created by justin on 2020/10/14.
//
#include "../include/Player.h"
#include <cmath>

Player::Player() : _shape(sf::Vector2f(20, 30)) {
    _shape.setFillColor(sf::Color::Blue);
    _shape.setOrigin(16, 16);
}

void Player::update(sf::Time deltaTime) {
    float seconds = deltaTime.asSeconds();
    if (rotation != 0) {
//        float angle = (rotation > 0 ? 1 : -1) * 180 * seconds;
        float angle = rotation * 180 * seconds;
        _shape.rotate(angle);
    }
    if (isMoving) {
        float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
        _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
    }
    _shape.move(_velocity * seconds);
}

void Player::processEvents() {
    isMoving = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    rotation = 0;
    rotation -= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    rotation += sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_shape, states);
}


