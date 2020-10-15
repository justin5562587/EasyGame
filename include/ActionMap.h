//
// Created by justin on 2020/10/15.
//

#ifndef EASYGAME_ACTIONMAP_H
#define EASYGAME_ACTIONMAP_H

#include <unordered_map>
#include "../include/Action.h"

template<typename T = int>
class ActionMap {
public:

    ActionMap(const ActionMap<T>&) = delete;

    ActionMap<T>& operator=(const ActionMap<T>&) = delete;

    ActionMap() = default;

    void map(const T& key, const Action& action);

    const Action& get(const T& key) const;

private:

    std::unordered_map<T, Action> _map;
};

#endif //EASYGAME_ACTIONMAP_H
