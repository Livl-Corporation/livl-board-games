//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_GAMEGUIINTERACTIONS_H
#define LIVL_GAMEGUIINTERACTIONS_H

#include <utility>
#include "forms/game/gamewindow.h"
#include "../interfaces/gameInteractions.h"

class GameGuiInteractions : public GameInteractions
{

public:

    GameGuiInteractions();

    void printGameInfos(const std::string &gameName, const std::vector<Player> &players) const override;
    void printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const override;
    void printNextRound(const PlayerId &playerId, unsigned int round) const override;
    void printInfo(const std::string &message) const override;
    void printError(const std::string &message) const override;
    void printWinner(const PlayerId &playerId) const override;
    void printDraw() const override;
    void printComputerPlay() const override;
private:
    std::shared_ptr<GameWindow> gameWindow;
};

#endif //LIVL_GAMEGUIINTERACTIONS_H
