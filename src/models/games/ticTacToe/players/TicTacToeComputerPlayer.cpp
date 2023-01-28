//
// Created by Franck GUTMANN on 19/01/2023.
//

#include <QDebug>
#include "TicTacToeComputerPlayer.h"
#include "models/Grid.cpp"

void TicTacToeComputerPlayer::play(const std::shared_ptr<Grid<Token>> &grid) {
    std::vector<Position> freePositions = grid->getEmptyPositions();
    int positionSelected = Shared::randomInt(0, static_cast<int>(freePositions.size()));
    onPositionSelected(freePositions[positionSelected]) ;
}