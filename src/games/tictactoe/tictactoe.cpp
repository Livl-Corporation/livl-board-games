#include "tictactoe.hpp"

Position TicTacToe::playAsComputer(const PlayerId &playerId)
{
    std::vector<Position> freePositions = this->getGrid()->getEmptyPositions();
    int positionSelected = Shared::randomInt(0, static_cast<int>(freePositions.size()));
    return freePositions[positionSelected];
}