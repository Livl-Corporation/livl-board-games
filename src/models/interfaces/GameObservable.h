//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_GAMEOBSERVABLE_H
#define LIVL_GAMEOBSERVABLE_H

#include <memory>
#include "GameObserver.h"

class GameObservable {
public:
    virtual void attach(std::shared_ptr<GameObserver> &_observer) = 0;

    virtual void notifyError(const std::string &message) = 0;
    virtual void notifyMessage(const std::string &message) = 0;
    virtual void notifyAskForPosition() = 0;
    virtual void notifyAskForPosition(const std::string &message) = 0;
    virtual void notifyGameEnd(const std::string &message) = 0;

    virtual void notifyGameName() = 0;
    virtual void notifyRound() = 0;
    virtual void notifyGrid() = 0;
    virtual void notifyPlayers() = 0;

};

#endif //LIVL_GAMEOBSERVABLE_H

