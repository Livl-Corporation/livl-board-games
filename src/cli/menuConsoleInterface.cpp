//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "menuConsoleInterface.h"

MenuConsoleInteractions::MenuConsoleInteractions() {
    ConsoleHandler::printHeader("Welcome to LIVL Board Games");

    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("BOARD GAME CHOICE");
    // TODO
    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");
//    return ConsoleHandler::readInt();

    ConsoleHandler::printHeader("GAME MODE");
    // TODO
    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

//    return ConsoleHandler::readInt();

}
