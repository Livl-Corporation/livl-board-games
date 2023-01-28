//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_GAMEOBSERVER_H
#define LIVL_GAMEOBSERVER_H

#include "models/Round.h"

template <typename T>
class GameObserver {
public:
    virtual void update(const T &value) = 0; // Will disappear
    virtual void updateError(const std::string &message) = 0;
    virtual void updateRound(Round round) = 0;
    virtual void updateMessage(const std::string &message) = 0;
};

#endif //LIVL_GAMEOBSERVER_H