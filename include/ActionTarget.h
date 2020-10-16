//
// Created by justin on 2020/10/15.
//

#ifndef EASYGAME_ACTIONTARGET_H
#define EASYGAME_ACTIONTARGET_H

#include <SFML/Graphics.hpp>
#include <list>
#include "./Action.h"
#include "./ActionMap.h"

template<typename T = int>
class ActionTarget {
public:

    ActionTarget(const ActionTarget<T> &) = delete;

    ActionTarget<T> &operator=(const ActionTarget<T> &) = delete;

    using FuncType = std::function<void(const sf::Event &)>;

    ActionTarget(const ActionMap<T> &map);

    // for real time
    bool processEvent(const sf::Event &event) const;

    // for non real time
    void processEvents() const;

    void bind(const T &key, const FuncType &callback);

    void unbind(const T &key);

private:

    std::list<std::pair<T, FuncType> > _eventsRealTime;

    std::list<std::pair<T, FuncType> > _eventsPoll;

    const ActionMap<T> &_actionMap;

};

#include "../inline/ActionTarget.inl"

#endif //EASYGAME_ACTIONTARGET_H
