//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "guiInterface.h"

void GuiInterface::printGameInfos(const std::string &gameName, const std::vector<Player> &players) const {
    gameWindow->setGameName(gameName);
    gameWindow->createPlayers(players);
}

void GuiInterface::printNextRound(const PlayerId &playerId, unsigned int round) const {
    gameWindow->setRound(round);
    gameWindow->setActivePlayer(playerId);
}

void GuiInterface::printInfo(const std::string &message) const {
    gameWindow->setInfoText(message);
    gameWindow->setInfoTextColor("black");
}

void GuiInterface::printError(const std::string &message) const {
    gameWindow->setInfoText(message);
    gameWindow->setInfoTextColor("red");
}

void GuiInterface::printWinner(const PlayerId &playerId) const {
    gameWindow->setInfoText("Player's victory " + std::to_string(playerId) + " (" + Player::getPlayerChar(playerId) + ")");
    gameWindow->setInfoTextColor("green");
}

void GuiInterface::printDraw() const {
    gameWindow->setInfoText("Tie Game");
    gameWindow->setInfoTextColor("green");
}

void GuiInterface::printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const {
    gameWindow->setGrid(grid);
}

void GuiInterface::printComputerPlay() const {
    gameWindow->setInfoText("Computer is playing...");
    gameWindow->setInfoTextColor("black");
}
