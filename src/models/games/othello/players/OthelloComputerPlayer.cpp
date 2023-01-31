//
// Created by Franck GUTMANN on 30/01/2023.
//

#include "OthelloComputerPlayer.h"

void OthelloComputerPlayer::play(const std::shared_ptr<Grid<Token>> &grid) {
    // Get a list of all the valid positions that the computer can place its token
    std::vector<Position> validPositions = OthelloGameEvaluator::getValidPositions(this->getId(), *grid);

    // Use an evaluation function to determine the best position to place the token
    Position bestPosition = OthelloGameEvaluator::getBestPosition(validPositions, this->getId(), *grid);

    this->onPositionSelected(bestPosition);
}
