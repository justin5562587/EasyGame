//
// Created by justin on 2020/10/15.
//

#ifndef EASYGAME_ACTIONTARGET_H
#define EASYGAME_ACTIONTARGET_H

#include <SFML/Graphics.hpp>
#include <list>
#include <>
#include "../include/Action.h"

class ActionTarget {
public:

    using FuncType = std::function<void(const sf::Event &)>;

    ActionTarget();

    // for real time
    bool processEvent(const sf::Event &event) const;

    // for non real time
    void processEvents() const;

    void bind(const Action &action, const FuncType &callback);

    void unbind(const Action &action);

private:

    std::list<std::pair<Action, FuncType> > _eventsRealTime;

    std::list<std::pair<Action, FuncType> > _eventsPoll;

};

#endif //EASYGAME_ACTIONTARGET_H
