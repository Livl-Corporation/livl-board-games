#include "tictactoe.hpp"

Position TicTacToe::playAsComputer(const PlayerId &playerId)
{
    std::vector<Position> freePositions = this->getGrid().getEmptyPositions();

    int positionSelected = Shared::randomInt(0, freePositions.size());

    // Keep trying to place a piece on the grid until a valid position is found
    while (!this->getGrid().place(freePositions[positionSelected], playerId))
    {
        positionSelected = Shared::randomInt(0, freePositions.size());
    }

    return freePositions[positionSelected];
}