#include "tictactoe.hpp"

Position TicTacToe::playAsComputer(const PlayerId &playerId)
{
    std::vector<Position> freePositions = getGrid()->getEmptyPositions();
    int positionSelected = Shared::randomInt(0, static_cast<int>(freePositions.size()));
    return freePositions[positionSelected];
}