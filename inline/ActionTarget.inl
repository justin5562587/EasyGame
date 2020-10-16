//
// Created by justin on 2020/10/15.
//
#include "../include/ActionTarget.h"

template<typename T>
ActionTarget<T>::ActionTarget(const ActionMap<T> &map) {

}

template<typename T>
bool ActionTarget<T>::processEvent(const sf::Event &event) const {
    bool res = false;
    for (auto &action : _eventsPoll) {
        if (action.first == event) {
            action.second(event);
            res = true;
            break;
        }
    }
    return res;
}

template<typename T>
void ActionTarget<T>::processEvents() const {
    for (auto &action : _eventsRealTime) {
        if (action.first.test()) {
            action.second(action.first._event);
        }
    }
}

template<typename T>
void ActionTarget<T>::bind(const Action &action, const FuncType &callback) {
    if (action._type & Action::Type::RealTime) {
        _eventsRealTime.emplace_back(action, callback);
    } else {
        _eventsPoll.emplace_back(action, callback);
    }
}

template<typename T>
void ActionTarget<T>::unbind(const Action &action) {
    auto remove_func = [&action](const std::pair<Action, FuncType> &pair) -> bool {
        return pair.first == action;
    };

    if (action._type & Action::Type::RealTime) {
        _eventsRealTime.remove_if(remove_func);
    } else {
        _eventsPoll.remove_if(remove_func);
    }

}

