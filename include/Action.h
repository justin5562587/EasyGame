//
// Created by justin on 2020/10/14.
//

#ifndef EASYGAME_ACTION_H
#define EASYGAME_ACTION_H

#include <SFML/Graphics.hpp>

class Action {
public:

    enum Type {
        RealTime = 1,
        Pressed = 1 << 1,
        Released = 1 << 2;
    };

    Action(const Action &other);

    Action &operator=(const Action &other);

    Action(const sf::Keyboard::Key &key, int type = Type::RealTime | Type::Pressed);

    Action(const sf::Mouse::Button &button, int type = Type::RealTime | Type::Pressed);

    bool test() const;

    bool operator==(const sf::Event &event) const;

    bool operator==(const Action &other) const;

private:

    friend class ActionTarget;

    sf::Event _event;
    int _type;

};

#endif //EASYGAME_ACTION_H
