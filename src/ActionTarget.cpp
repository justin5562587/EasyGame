//
// Created by justin on 2020/10/15.
//
#include "../include/ActionTarget.h"

ActionTarget::ActionTarget() {

}

bool ActionTarget::processEvent(const sf::Event &event) const {
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

void ActionTarget::processEvents() const {
    for (auto &action : _eventsRealTime) {
        if (action.first.test()) {
            action.second(action.first._event);
        }
    }
}

void ActionTarget::bind(const Action &action, const FuncType &callback) {

}

void ActionTarget::unbind(const Action &action) {}

