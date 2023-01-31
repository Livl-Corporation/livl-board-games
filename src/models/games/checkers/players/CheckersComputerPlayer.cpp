//
// Created by Julien on 30/01/2023.
//

#include "CheckersComputerPlayer.h"

void CheckersComputerPlayer::play(const std::shared_ptr<Grid<Token>> &grid) {

    if(!isOriginPositionSelected) {
        getBothDestination(grid);
        isOriginPositionSelected = true;
        this->onPositionSelected(originPosition.value());
    } else {
        isOriginPositionSelected = false;
        this->onPositionSelected(destinationPosition.value());
    }

}

void CheckersComputerPlayer::getBothDestination(const std::shared_ptr<Grid<Token>> &grid) {
    std::vector<Position> validMovesPosition;

    for (int i = 0; i < grid->getColCount(); i++) {
        for (int j = 0; j < grid->getRowCount(); j++) {
            Position position = Position(i, j);
            if (grid->getElementAt(position)->getPlayerId() == getId())
                {
                    std::vector<Position> validMoves = CheckersEvaluator::getValidTokenMoves(*grid, position);
                    if (!validMoves.empty()) {
                        validMovesPosition.insert(validMovesPosition.end(), validMoves.begin(), validMoves.end());
                        destinationPosition = validMovesPosition[0];
                        originPosition = position;
                        return;
                    }
                }
            }
    }
}
