//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_GAMEOBSERVABLE_H
#define LIVL_GAMEOBSERVABLE_H

#include <memory>
#include "GameObserver.h"

template <typename T>
class GameObservable {
public:
    virtual void attach(std::shared_ptr<GameObserver<T>> &_observer) = 0;
    virtual void notify(const T &value) = 0;
    virtual void notifyError(const std::string &message) = 0;
};

#endif //LIVL_GAMEOBSERVABLE_H

