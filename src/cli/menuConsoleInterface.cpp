//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "menuConsoleInterface.h"

MenuConsoleInteractions::MenuConsoleInteractions() {
    ConsoleHandler::printHeader("Welcome to LIVL Board Games");

    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("BOARD GAME CHOICE");

    for (int i = 0; i < GameFactory::gameList.size(); i++) {
        ConsoleHandler::printLine("[" + std::to_string(i+1) + "] " + GameFactory::gameList[i]);
    }

    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

    int gameSelection = ConsoleHandler::readInt();

    ConsoleHandler::printHeader("GAME MODE");

    for (int i = 0; i < MenuInteractions::playerList.size(); i++) {
        ConsoleHandler::printLine("[" + std::to_string(i+1) + "] " + MenuInteractions::playerList[i]);
    }

    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

    int playerSelection = ConsoleHandler::readInt();

    if (gameSelection > 0 && gameSelection <= GameFactory::gameList.size() && playerSelection > 0 && playerSelection <= MenuInteractions::playerList.size()) {
        GameFactory::startGame(gameSelection, playerSelection);
    } else {
        ConsoleHandler::printLine("Exiting...");
    }

}
