//
// Created by Julien on 29/01/2023.
//

#include "ConnectFourComputerPlayer.h"

void ConnectFourComputerPlayer::play(const std::shared_ptr<Grid<Token>> &grid) {
    int col, row = 0;

    col = Shared::randomInt(0, static_cast<int>(grid->getXSize() - 1));

    try
    {
        row = ConnectFour::firstRowAvailableInCol(grid, col);
    }
    catch (...)
    {
    }

    this->onPositionSelected({col, row});
}