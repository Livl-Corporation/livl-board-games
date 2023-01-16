//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "menuConsoleInterface.h"
#include "consoleHandler.hpp"

void MenuConsoleInteractions::printMenu(const std::vector<std::string> &gameList,
                                        const std::vector<std::string> &playerList) const {

    ConsoleHandler::printHeader("Welcome to LIVL Board Games");

    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("BOARD GAME CHOICE");
    ConsoleHandler::printLine("1. Tic-Tac-Toe");
    ConsoleHandler::printLine("2. Power 4");
    ConsoleHandler::printLine("3. Othello");
    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");
//    return ConsoleHandler::readInt();

    ConsoleHandler::printHeader("GAME MODE");
    ConsoleHandler::printLine("1. Against the computer");
    ConsoleHandler::printLine("2. 2 players");
    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

//    return ConsoleHandler::readInt();

}
