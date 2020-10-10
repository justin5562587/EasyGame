//
// Created by justin on 2020/10/10.
//

#include "../include/Player.h"

Player::Player() : triangle(sf::Triangles, 3) {
    setTriangle();
}

void Player::setTriangle() {
    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 10.f);
    triangle[2].position = sf::Vector2f(100.f, 100.f);

// define the color of the triangle's points
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;
}

const sf::VertexArray& Player::getTriangle() {
    return triangle;
}
