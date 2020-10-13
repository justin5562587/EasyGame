//
// Created by justin on 2020/10/10.
//
#ifndef EASYGAME_GAME_H
#define EASYGAME_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game {

public:
    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    Game();

    void run();

private:
    void processEvents();

    void update();

    void render();

    sf::RenderWindow _window;

    sf::CircleShape _player;

};


#endif //EASYGAME_GAME_H
