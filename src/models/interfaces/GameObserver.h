//
// Created by Franck GUTMANN on 28/01/2023.
//

#ifndef LIVL_GAMEOBSERVER_H
#define LIVL_GAMEOBSERVER_H

#include "models/Round.h"

class GameObserver {
public:
    virtual void updateError(const std::string &message) = 0;
    virtual void updateMessage(const std::string &message) = 0;
    virtual void updateAskForPosition(const std::string &message, unsigned int numberOfValues) = 0;

    virtual void updateGameName(const std::string &gameName) = 0;
    virtual void updateRound(Round round, const std::shared_ptr<Player> &player) = 0;
    virtual void updateGrid(const Grid<Token> &grid) = 0;
    virtual void updatePlayers(const std::vector<std::shared_ptr<Player>> &players) = 0;
};

#endif //LIVL_GAMEOBSERVER_H