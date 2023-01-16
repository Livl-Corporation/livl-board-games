//
// Created by Franck GUTMANN on 16/01/2023.
//

#include "gameConsoleInteractions.h"

void GameConsoleInteractions::printGameInfos(const std::string &gameName, const std::vector<Player> &players) const {
    ConsoleHandler::printTitle(gameName);
}

void GameConsoleInteractions::printNextRound(const PlayerId &playerId, unsigned int round) const {
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("Round N° " + std::to_string(round));
}

void GameConsoleInteractions::printInfo(const std::string &message) const {
    ConsoleHandler::printLine(message);
}

void GameConsoleInteractions::printError(const std::string &message) const {
    ConsoleHandler::printLine(message);
}

void GameConsoleInteractions::printWinner(const PlayerId &playerId) const {
    ConsoleHandler::printTitle("Player's victory " + std::to_string(playerId
    ) + " (" + Player::getPlayerChar(playerId) + ")");
}

void GameConsoleInteractions::printDraw() const {
    ConsoleHandler::printTitle(std::string("Tie Game"));
}

void GameConsoleInteractions::printGrid(const std::shared_ptr<Grid<PlayerId>> &grid) const {
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

void GameConsoleInteractions::printComputerPlay() const {
    ConsoleHandler::printLine("Computer is playing...");

}
