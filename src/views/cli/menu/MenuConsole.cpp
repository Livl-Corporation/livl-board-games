//
// Created by Julien on 21/01/2023.
//

#include "MenuConsole.h"
#include "views/cli/game/GameConsole.h"

void MenuConsole::displayGameList(const std::vector<std::string> &gameList) {
    ConsoleHandler::printHeader("Welcome to LIVL Board Games");

    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("BOARD GAME CHOICE");

    for (int i = 0; i < gameList.size(); i++) {
        ConsoleHandler::printLine("[" + std::to_string(i+1) + "] " + gameList[i]);
    }

    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

    gameSelection = static_cast<GameMode>(ConsoleHandler::readInt());
}

void MenuConsole::displayPlayerList(const std::vector<std::string> &playerList) {
    ConsoleHandler::printHeader("GAME MODE");

    for (int i = 0; i < playerList.size(); i++) {
        ConsoleHandler::printLine("[" + std::to_string(i+1) + "] " + playerList[i]);
    }

    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

    playerSelection = static_cast<PlayMode>(ConsoleHandler::readInt());
}

void MenuConsole::show() {
    this->displayGameList(MenuData::players);
    this->displayPlayerList(MenuData::games);

    if (gameSelection > 0 && gameSelection <= MenuData::games.size() && playerSelection > 0 && playerSelection <= MenuData::players.size()) {
        this->controller->onGameChoose(gameSelection, playerSelection, std::make_shared<GameConsole>());
    } else {
        ConsoleHandler::printLine("Exiting...");
    }
}
