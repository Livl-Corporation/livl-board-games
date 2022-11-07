#include "game.hpp"
#include "player.hpp"
#include "cell.hpp"
#include "grid.hpp"
#include <iostream>
#include <cstdio>

void Game::play() {
    
}

void Game::nextRound()
{
    round++;
    std::cout << "Tour N° " << round << std::endl;

    // Determines who is playing this round
    unsigned int playerIndex = round % playerCount;
    Player player = players[playerIndex];
    int playerId = player.getId();

    std::cout << "Joueur " << playerId << ", c'est à toi !" << std::endl;

    // Ask him in which cell he wants to place his cell and place it in the grid
    Cell cell;
    do {
        cell = askForCell();
    } while (!grid.place(cell, playerId));

    // TODO : Handle computer

    // Display grid
    grid.displayGrid();

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
    else 
    {
        // Otherwhise, next round.
        nextRound();
    }


}

bool Game::hasWon(int id) const
{
    // if max consecutive player symbols > consecutiveSymbolsToWin, he has won !
    return grid.getMaxConsecutiveIds(id) >= consecutiveSymbolsToWin;
}

Cell Game::askForCell() 
{
    std::cout << "Où voulez vous placer votre pion ? (x,y)" << std::endl;
    unsigned int x, y;
    scanf("%d,%d", &x, &y);
    return {x: x, y: y};
}

void Game::win(int playerId) {

}

void Game::tie() {

}