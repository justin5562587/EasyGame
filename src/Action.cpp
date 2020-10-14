//
// Created by justin on 2020/10/14.
//
#include "../include/Action.h"

// constructor1
Action::Action(const Action &other) : _type(other._type) {
    std::memcpy(&_event, &other._event, sizeof(sf::Event));
}

// operator=
Action &Action::operator=(const Action &other) {
    std::memcpy(&_event, &other._event, sizeof(sf::Event));
    _type = other._type;
    return *this;
}

// constructor2
Action::Action(const sf::Keyboard::Key &key, int type) : _type(type) {
    _event.type = sf::Event::EventType::KeyPressed;
    _event.key.code = key;
}

// constructor3
Action::Action(const sf::Mouse::Button &button, int type) : _type(type) {
    _event.type = sf::Event::EventType::MouseButtonPressed;
    _event.mouseButton.button = button;
}

// operator==
bool Action::operator==(const sf::Event &event) const {
    bool res = false;
    switch (event.type) {
        case sf::Event::EventType::KeyPressed:
            if (_type & Type::Pressed and _event.type == sf::Event::EventType::KeyPressed) {
                res = event.key.code == _event.key.code;
            }
            break;
        case sf::Event::EventType::KeyReleased:
            if (_type & Type::Released and _event.type == sf::Event::EventType::KeyPressed) {
                res = event.key.code == _event.key.code;
            }
            break;
        case sf::Event::EventType::MouseButtonPressed:
            if (_type & Type::Pressed and _event.type == sf::Event::EventType::MouseButtonPressed) {
                res = event.mouseButton.button == _event.mouseButton.button;
            }
            break;
        case sf::Event::EventType::MouseButtonReleased:
            if (_type & Type::Released and _event.type == sf::Event::EventType::MouseButtonPressed) {
                res = event.mouseButton.button == _event.mouseButton.button;
            }
            break;
        default:
            break;
    }
    return res;
}

//

