//
// Created by Franck GUTMANN on 16/01/2023.
//
#pragma once

#include "../models/player.hpp"
#include "game.hpp"

class GameInterface {

public:

    /**
     * @brief Print game titles & others infos (eg. : player names)
     * @param game
     */
    virtual void printGameInfos(const std::string &gameName, const std::vector<Player> &players) const = 0;

    virtual void printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const = 0;

    /**
     * @brief Update the round number & the actual game player
     * @param game
     * @param playerId
     */
    virtual void printNextRound(const PlayerId &playerId, unsigned int round) const = 0;

    virtual void printInfo(const std::string &message) const = 0;

    virtual void printError(const std::string &message) const = 0;

    virtual void printWinner(const PlayerId &playerId) const = 0;

    virtual void printDraw() const = 0;

    virtual void printComputerPlay() const = 0;

};