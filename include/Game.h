//
// Created by justin on 2020/10/10.
//
#ifndef EASYGAME_GAME_H
#define EASYGAME_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "./Player.h"

class Game {

public:

    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    Game();

    void run(int minimum_frame_per_seconds);

private:
    void processEvent();

    void update(sf::Time deltaTime);

    void render();

    sf::RenderWindow _window;

    Player _player;

};


#endif //EASYGAME_GAME_H
