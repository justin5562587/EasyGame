//
// Created by justin on 2020/10/10.
//
#ifndef EASYGAME_PLAYER_H
#define EASYGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player {

public:

    Player(const Player&) = delete;

    Player& operator=(const Player&) = delete;

    Player();

    const sf::VertexArray& getTriangle();

private:

    void setTriangle();

    sf::VertexArray triangle;

};


#endif //EASYGAME_PLAYER_H
