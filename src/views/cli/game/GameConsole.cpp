//
// Created by Julien on 23/01/2023.
//

#include "GameConsole.h"
#include <QDebug>


void GameConsole::printGameInfos(const std::string &gameName, const std::vector<std::shared_ptr<Player>> &players) const {
    ConsoleHandler::printTitle(gameName);
    ConsoleHandler::printLine("Players :");
    for (const auto &player : players) {
        ConsoleHandler::printLine(" - " + player->getName() + " (" + std::to_string(player->getId()) + ")");
    }
}

void GameConsole::printNextRound(const Player &player, unsigned int round) const {
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("Round N° " + std::to_string(round));
    ConsoleHandler::printLine("Player's turn : " + player.getName() + " (" + std::to_string(player.getId()) + ")");
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
            std::string characterAsString(1, grid.getElementAt({.x =  col, .y =  row}).getPlayerId());
            ConsoleHandler::print(characterAsString);

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

void GameConsole::update(const Game &value) {
    printGameInfos(value.getName(), value.getPlayers());
    printGrid(*value.getGrid());
    printNextRound(*value.getCurrentPlayer(), value.getRound());
}

void GameConsole::updateError(const std::string &message) {
    ConsoleHandler::printLine(message);
}

void GameConsole::updateMessage(const std::string &message) {
    ConsoleHandler::printLine(message);
}

void GameConsole::updateRound(Round round) {
    ConsoleHandler::printLine("Round : " + std::to_string(round));
}




