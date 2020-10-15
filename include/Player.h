//
// Created by justin on 2020/10/14.
//

#ifndef EASYGAME_PLAYER_H
#define EASYGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player : public sf::Drawable {

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

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::RectangleShape _shape;
    sf::Vector2f _velocity;

    bool isMoving;
    int rotation;

};

#endif //EASYGAME_PLAYER_H
