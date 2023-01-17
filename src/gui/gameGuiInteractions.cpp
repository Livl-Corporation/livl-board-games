//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "gameGuiInteractions.h"

GameGuiInteractions::GameGuiInteractions() {
    gameWindow = std::make_shared<GameWindow>();
}

void GameGuiInteractions::printGameInfos(const std::string &gameName, const std::vector<Player> &players) const {
    gameWindow->setGameName(gameName);
    gameWindow->createPlayers(players);
    gameWindow->show();
}

void GameGuiInteractions::printNextRound(const PlayerId &playerId, unsigned int round) const {
    gameWindow->setRound(round);
    gameWindow->setActivePlayer(playerId);
}

void GameGuiInteractions::printInfo(const std::string &message) const {
    gameWindow->setInfoText(message);
    gameWindow->setInfoTextColor("black");
}

void GameGuiInteractions::printError(const std::string &message) const {
    gameWindow->setInfoText(message);
    gameWindow->setInfoTextColor("red");
}

void GameGuiInteractions::printWinner(const PlayerId &playerId) const {
    gameWindow->setInfoText("Player's victory " + std::to_string(playerId) + " (" + Player::getPlayerChar(playerId) + ")");
    gameWindow->setInfoTextColor("green");
}

void GameGuiInteractions::printDraw() const {
    gameWindow->setInfoText("Tie Game");
    gameWindow->setInfoTextColor("green");
}

void GameGuiInteractions::printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const {
    gameWindow->setGrid(grid);
}

void GameGuiInteractions::printComputerPlay() const {
    gameWindow->setInfoText("Computer is playing...");
    gameWindow->setInfoTextColor("black");
}