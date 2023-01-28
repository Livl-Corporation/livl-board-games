//
// Created by Julien on 23/01/2023.
//

#include "GameConsole.h"

void GameConsole::printGameInfos(const std::string &gameName, const std::vector<Player> &players) const {
    ConsoleHandler::printTitle(gameName);
}

void GameConsole::printNextRound(const PlayerId &playerId, unsigned int round) const {
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("Round N° " + std::to_string(round));
}

void GameConsole::printInfo(const std::string &message) const {
    ConsoleHandler::printLine(message);
}

void GameConsole::printError(const std::string &message) const {
    ConsoleHandler::printLine(message);
}

void GameConsole::printWinner(const PlayerId &playerId) const {
    //ConsoleHandler::printTitle("Player's victory " + std::to_string(playerId
    //) + " (" + Player::getPlayerChar(playerId) + ")");
}

void GameConsole::printDraw() const {
    ConsoleHandler::printTitle(std::string("Tie Game"));
}

void GameConsole::printGrid(const Grid<Token> &grid) const {
    ConsoleHandler::print("\n   ");
    for (int col = 0; col < grid.getXSize(); col++)
    {
        ConsoleHandler::print(std::to_string(col + 1) + " ");
    }

    ConsoleHandler::print("\n  ┌");
    for (int col = 0; col < (grid.getXSize() * 2) - 1; col++)
    {
        if (col % 2 == 0)
        {
            ConsoleHandler::print("─");
        }
        else
        {
            ConsoleHandler::print("┬");
        }
    }
    ConsoleHandler::printLine("┐");

    for (int row = 0; row < grid.getYSize(); row++)
    {

        ConsoleHandler::print(std::to_string(row + 1) + " │");

        for (int col = 0; col < grid.getXSize(); col++)
        {
            //std::string characterAsString(1, Player::getPlayerChar(grid->getElementAt({.x =  col, .y =  row})));
            //ConsoleHandler::print(characterAsString);

            if (col < grid.getXSize() - 1)
            {
                ConsoleHandler::print("│");
            }
        }
        ConsoleHandler::printLine("│");
    }

    ConsoleHandler::print("  └");
    for (int col = 0; col < (grid.getXSize() * 2) - 1; col++)
    {
        if (col % 2 == 0)
        {
            ConsoleHandler::print("─");
        }
        else
        {
            ConsoleHandler::print("┴");
        }
    }
    ConsoleHandler::printLine("┘");
}

void GameConsole::printComputerPlay() const {
    ConsoleHandler::printLine("Computer is playing...");

}

void GameConsole::show() {
    ConsoleHandler::printLine("Welcome !");
}

//void GameConsole::attachObserver() {
//    this->controller->getGame()->Subject::attach(shared_from_this());
//}
//
//void GameConsole::update(const Game &game) {
//
//}
//
//std::shared_ptr<Subject<Position>> GameConsole::getPositionSubject() {
//    return {};
//}
