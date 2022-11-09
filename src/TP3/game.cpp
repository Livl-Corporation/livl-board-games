#include "game.hpp"
#include "player.hpp"
#include "cell.hpp"
#include "grid.hpp"
#include "functions.hpp"

#include "exceptions/out-of-bounds-exception.hpp"

#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>

Game::Game(
    std::string name,
    unsigned int xSize,
    unsigned int ySize,
    unsigned int pointsToWin,
    std::vector<Player> players) : players(players), grid(xSize, ySize), name(name)
{
    this->playerCount = players.size();
    this->consecutiveSymbolsToWin = pointsToWin;
}

void Game::play()
{
    std::cout << std::endl
              << "*----------------------*" << std::endl;
    std::cout << "     STARTING GAME     " << std::endl;
    std::cout << "*----------------------*" << std::endl;

    std::cout << "***** " << this->getName() << " *****" << std::endl;

    do
    {
        this->nextRound();
    } while (!this->isFinished);
}

void Game::nextRound()
{
    round++;
    std::cout << "----------" << std::endl;
    std::cout << std::endl
              << "Tour N° " << this->getRound() << std::endl;

    // Determines who is playing this round
    unsigned int playerIndex = (round - 1) % playerCount;
    Player player = players[playerIndex];
    int playerId = player.getId();

    if (player.getIsComputer())
    {
        // Player is computer
        Cell cell = this->playAsComputer(playerId);
        std::cout << "Joué par l'ordinateur en " << cell.x << "," << cell.y << "." << std::endl;
    }
    else
    {
        // Player is a real person
        std::cout << "Joueur " << playerId << ", c'est à toi !" << std::endl;

        // Ask him in which cell he wants to place his cell and place it in the grid
        Cell cell;
        do
        {

            this->getGrid().displayGrid();

            cell = askForCell(getPlayerChar(playerId));

        } while (!this->getGrid().place(cell, playerId));
    }

    // Verify if player has won
    if (hasWon(playerId))
    {
        win(playerId);
    }
    else if (grid.isGridFull())
    {
        // If grid is full, tie
        tie();
    }
}

bool Game::hasWon(int id) const
{
    // if max consecutive player symbols > consecutiveSymbolsToWin, he has won !
    return grid.getMaxConsecutiveIds(id) >= consecutiveSymbolsToWin;
}

Cell Game::askForCell(const char playerChar)
{
    std::cout << "Où voulez vous placer votre pion (" << playerChar << ") entre 1,1 et " << this->getGrid().getXSize() << "," << this->getGrid().getYSize() << " ?" << std::endl;

    unsigned int x, y;
    scanf("%d,%d", &x, &y);
    return {x : x - 1, y : y - 1};
}

Cell Game::playAsComputer(int playerId)
{
    std::vector<Cell> freeCells = this->getGrid().getFreeCells();

    srand(time(NULL));
    int cellSelected = randomInt(0, freeCells.size());

    this->getGrid().place(freeCells[cellSelected], playerId);

    return freeCells[cellSelected];
}

void Game::win(int playerId)
{
    std::cout << std::endl
              << "*------------*" << std::endl;
    std::cout << "     Victoire du joueur " << playerId << " (" << getPlayerChar(playerId) << ")     ";
    std::cout << std::endl
              << "*------------*" << std::endl;

    this->getGrid().displayGrid();

    this->isFinished = true;
}

void Game::tie()
{
    std::cout << std::endl
              << "*------------*" << std::endl;
    std::cout << "     Match nul     ";
    std::cout << std::endl
              << "*------------*" << std::endl;

    this->getGrid().displayGrid();

    this->isFinished = true;
}

std::vector<Player> Game::getPlayers() const
{
    std::vector<Player> vect(this->players);
    return vect;
}