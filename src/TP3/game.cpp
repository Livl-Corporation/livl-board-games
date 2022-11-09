#include "game.hpp"
#include "player.hpp"
#include "cell.hpp"
#include "grid.hpp"
#include "functions.hpp"

#include "exceptions/out-of-bounds-exception.hpp"

#include <iostream>
#include <cstdio>
#include <vector>

Game::Game(
    std::string name, 
    unsigned int xSize, 
    unsigned int ySize, 
    unsigned int pointsToWin, 
    std::vector<Player> players
) : players(players), grid(xSize, ySize), name(name)
{
    this->playerCount = players.size();
    this->consecutiveSymbolsToWin = pointsToWin;
}

Game::~Game() {
    delete &this->name;
    delete &this->players;
    delete &this->grid;
}

void Game::play() {
    std::cout << "*** STARTING GAME ***" << std::endl;
    std::cout << "***** " << this->getName() << " *****" << std::endl;

    do {
        this->nextRound();
    } while(!this->isFinished);

}

void Game::nextRound()
{
    round++;
    std::cout << std::endl << "Tour N° " << this->getRound() << std::endl;

    // Determines who is playing this round
    unsigned int playerIndex = (round-1) % playerCount;
    Player player = players[playerIndex];
    int playerId = player.getId();

    std::cout << "Joueur " << playerId << ", c'est à toi !" << std::endl;

    // Ask him in which cell he wants to place his cell and place it in the grid
    Cell cell;
    do {

        this->grid.displayGrid();

        cell = askForCell(getPlayerChar(playerId));

    } while (!grid.place(cell, playerId));

    // TODO : Handle computer

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
    std::cout << "Où voulez vous placer votre pion (" << playerChar << ") ? (x,y)" << std::endl;
    unsigned int x, y;
    scanf("%d,%d", &x, &y);
    return {x: x, y: y};
}

void Game::win(int playerId) {
    std::cout << "it's a win for " << playerId << std::endl;
    this->isFinished = true;
}

void Game::tie() {
    std::cout << "game ended, nobody won !" << std::endl;
    this->isFinished = true;
}