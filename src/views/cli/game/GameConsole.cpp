//
// Created by Julien on 23/01/2023.
//

#include "GameConsole.h"

void GameConsole::show() {
    ConsoleHandler::printLine("Welcome !");
}

void GameConsole::updateError(const std::string &message) {
    ConsoleHandler::printLine(message);
}

void GameConsole::updateMessage(const std::string &message) {
    ConsoleHandler::printLine(message);
}

void GameConsole::updateRound(Round round, const std::shared_ptr<Player> &player) {
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("Round N° " + std::to_string(round));
    ConsoleHandler::printLine("Player's turn : " + player->getName() + " (" + std::to_string(player->getId()) + ")");
}

void GameConsole::updateGrid(const Grid<Token> &grid) {
    ConsoleHandler::print("\n   ");
    for (int col = 0; col < grid.getColCount(); col++)
    {
        ConsoleHandler::print(std::to_string(col + 1) + " ");
    }

    ConsoleHandler::print("\n  ┌");
    for (int col = 0; col < (grid.getColCount() * 2) - 1; col++)
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

    for (int row = 0; row < grid.getRowCount(); row++)
    {

        ConsoleHandler::print(std::to_string(row + 1) + " │");

        for (int col = 0; col < grid.getColCount(); col++)
        {
            ConsoleHandler::print(grid.getElementAt(Position(row, col))->getDisplayString());

            if (col < grid.getColCount() - 1)
            {
                ConsoleHandler::print("│");
            }
        }
        ConsoleHandler::printLine("│");
    }

    ConsoleHandler::print("  └");
    for (int col = 0; col < (grid.getColCount() * 2) - 1; col++)
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

void GameConsole::updatePlayers(const std::vector<std::shared_ptr<Player>> &players) {
    ConsoleHandler::printLine("Players :");
    for (const auto &player : players) {
        ConsoleHandler::printLine(" - " + player->getName() + " (" + std::to_string(player->getId()) + ")");
    }
}

void GameConsole::updateGameName(const std::string &gameName) {
    ConsoleHandler::printTitle(gameName);
}

void GameConsole::updateAskForPosition(const std::string &message, unsigned int numberOfValues) {
    ConsoleHandler::printLine(message);

    std::vector<int> values = ConsoleHandler::readValues(numberOfValues);

    int row = values[0]-1;
    int col = numberOfValues == 1 ? row : values[1]-1;

    controller->onPositionSelected({row, col});
}

void GameConsole::updateGameEnd(const std::string &message) {
    ConsoleHandler::printTitle("Game End");
    ConsoleHandler::printLine(message);
}




