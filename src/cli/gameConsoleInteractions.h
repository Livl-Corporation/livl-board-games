//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_GAMECONSOLEINTERACTIONS_H
#define LIVL_GAMECONSOLEINTERACTIONS_H

#include "../interfaces/gameInteractions.h"
#include "../interfaces/game.hpp"
#include "consoleHandler.hpp"

class GameConsoleInteractions : public GameInteractions
{

public:

    GameConsoleInteractions() = default;

    void printGameInfos(const std::string &gameName, const std::vector<Player> &players) const override;
    void printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const override;
    void printNextRound(const PlayerId &playerId, unsigned int round) const override;
    void printInfo(const std::string &message) const override;
    void printError(const std::string &message) const override;
    void printWinner(const PlayerId &playerId) const override;
    void printDraw() const override;
    void printComputerPlay() const override;

};

#endif //LIVL_GAMECONSOLEINTERACTIONS_H
