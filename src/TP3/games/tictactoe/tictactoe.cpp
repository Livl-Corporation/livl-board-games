#include "tictactoe.hpp"

Position TicTacToe::playAsComputer(const PlayerId &playerId)
{
    std::vector<Position> freePositions = this->getGrid().getEmptyPositions();

    int positionSelected = Shared::randomInt(0, static_cast<int>(freePositions.size()));

    // Keep trying to place a piece on the grid until a valid position is found
    while (!this->getGrid().getElementAt(freePositions[positionSelected]))
    {
        positionSelected = Shared::randomInt(0, static_cast<int>(freePositions.size()));
    }

    return freePositions[positionSelected];
}