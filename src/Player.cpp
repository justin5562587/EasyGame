//
// Created by justin on 2020/10/14.
//
#include "../include/Player.h"
#include <cmath>

Player::Player() : _shape(sf::Vector2f(32, 32)), _isMoving(false), _rotation(0) {
    _shape.setFillColor(sf::Color::Blue);
    _shape.setOrigin(16, 16);

    bind(Action(sf::Keyboard::Up), [this](const sf::Event &) {
        _isMoving = true;
    });

    bind(Action(sf::Keyboard::Left), [this](const sf::Event &) {
        _rotation -= 1;
    });
    bind(Action(sf::Keyboard::Right), [this](const sf::Event &) {
        _rotation += 1;
    });
}

void Player::update(sf::Time deltaTime) {
    float seconds = deltaTime.asSeconds();
    if (_rotation != 0) {
//        float angle = (rotation > 0 ? 1 : -1) * 180 * seconds;
        float angle = _rotation * 180 * seconds;
        _shape.rotate(angle);
    }
    if (_isMoving) {
        float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
        _velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
    }
    _shape.move(_velocity * seconds);
}

void Player::processEvents() {
    _isMoving = false;
    _rotation = 0;
    ActionTarget::processEvents();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_shape, states);
}


