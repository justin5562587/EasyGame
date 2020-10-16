//
// Created by justin on 2020/10/14.
//

#ifndef EASYGAME_PLAYER_H
#define EASYGAME_PLAYER_H

#include "../include/ActionTarget.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player : public sf::Drawable, public ActionTarget<int> {

public:

    Player(const Player &) = delete;

    Player &operator=(const Player &) = delete;

    Player();

    template<typename ...Args>
    void setPosition(Args &&...args) {
        _shape.setPosition(std::forward<Args>(args)...);
    }

    void processEvents();

    void update(sf::Time deltaTime);

    enum PlayerInputs {
        Up, Left, Right
    };

    static void setDefaultInputs();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::RectangleShape _shape;

    sf::Vector2f _velocity;

    bool _isMoving;

    int _rotation;

    static ActionMap<int> _playeInputs;;

};

#endif //EASYGAME_PLAYER_H
