//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "consoleInterface.h"

void ConsoleInterface::printGameInfos(const std::string &gameName, const std::vector<Player> &players) const {
    ConsoleHandler::printTitle(gameName);
}

void ConsoleInterface::printNextRound(const PlayerId &playerId, unsigned int round) const {
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("Round N° " + std::to_string(round));
}

void ConsoleInterface::printInfo(const std::string &message) const {
    ConsoleHandler::printLine(message);
}

void ConsoleInterface::printError(const std::string &message) const {
    ConsoleHandler::printLine(message);
}

void ConsoleInterface::printWinner(const PlayerId &playerId) const {
    ConsoleHandler::printTitle("Player's victory " + std::to_string(playerId
    ) + " (" + Player::getPlayerChar(playerId) + ")");
}

void ConsoleInterface::printDraw() const {
    ConsoleHandler::printTitle(std::string("Tie Game"));
}

void ConsoleInterface::printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const {
    ConsoleHandler::print("\n   ");
    for (int col = 0; col < grid->getXSize(); col++)
    {
        ConsoleHandler::print(std::to_string(col + 1) + " ");
    }

    ConsoleHandler::print("\n  ┌");
    for (int col = 0; col < (grid->getXSize() * 2) - 1; col++)
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

    for (int row = 0; row < grid->getYSize(); row++)
    {

        ConsoleHandler::print(std::to_string(row + 1) + " │");

        for (int col = 0; col < grid->getXSize(); col++)
        {
            std::string characterAsString(1, Player::getPlayerChar(grid->getElementAt({.x =  col, .y =  row})));
            ConsoleHandler::print(characterAsString);

            if (col < grid->getXSize() - 1)
            {
                ConsoleHandler::print("│");
            }
        }
        ConsoleHandler::printLine("│");
    }

    ConsoleHandler::print("  └");
    for (int col = 0; col < (grid->getXSize() * 2) - 1; col++)
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

