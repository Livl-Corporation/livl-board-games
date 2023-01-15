#include "checkersPositionRequester.hpp"

Position CheckersPositionRequester::askForPosition(const PlayerId &playerId) const {
    Position from = promptAndValidatePosition("Player " + std::to_string(playerId) + ", select a position to move your piece from (x,y): ", playerId);

    Position to = promptAndValidateDestinationPosition("Player " + std::to_string(playerId) + ", select a destination position for your piece (x,y): ", playerId, from);

    return to;
}

Position CheckersPositionRequester::promptAndValidatePosition(const std::string &prompt, const PlayerId &playerId) const {
    Position position{};
    while (true) {
        ConsoleHandler::print(prompt);

        auto input = ConsoleHandler::readValues(2);
        position = {input[1] - 1, input[0] - 1};

        if (!this->getGrid()->isPositionInBounds(position)) {
            ConsoleHandler::printLine("Invalid position! The position is out of bounds.");
            continue;
        }

        if (this->getGrid()->getElementAt(position) != playerId) {
            ConsoleHandler::printLine("Invalid position! The position is not occupied by your piece.");
            continue;
        }

        break;
    }
    return position;
}

Position CheckersPositionRequester::promptAndValidateDestinationPosition(const std::string &prompt, const PlayerId &playerId, const Position &from) const {
    Position position{};
    while (true) {
        ConsoleHandler::print(prompt);

        auto input = ConsoleHandler::readValues(2);
        position = {input[1] - 1, input[0] - 1};

        if (!this->getGrid()->isPositionInBounds(position)) {
            ConsoleHandler::printLine("Invalid position! The position is out of bounds.");
            continue;
        }

        if (!this->getGrid()->isPositionEmpty(position)) {
            ConsoleHandler::printLine("Invalid position! The position is not empty.");
            continue;
        }

        if (!this->isMoveValid(playerId, from, position)) {
            ConsoleHandler::printLine("Invalid move! You can only move diagonally and not backward.");
            continue;
        }

        if (this->isCaptureMove(playerId, from, position)) {
            this->captureEnemyToken(from, position);
            ConsoleHandler::printLine("Congratulations ! You captured an enemy token.");
        }

        break;
    }

    // Remove the initial position from the grid if the move is valid
    this->getGrid()->replaceAt(from, NO_PLAYER);

    return position;
}

bool CheckersPositionRequester::captureEnemyToken(const Position &from, const Position &to) const {
    if(!getGrid()->isPositionInBounds(from) || !getGrid()->isPositionInBounds(to))
        return false;

    if(this->getGrid()->getElementAt(from) == NO_PLAYER || this->getGrid()->getElementAt(to) != NO_PLAYER)
        return false;

    int xDiff = abs(to.x - from.x);
    int yDiff = abs(to.y - from.y);

    if(xDiff != 2 || yDiff != 2)
        return false;

    Position enemyPos = {(to.x+from.x)/2, (to.y+from.y)/2};

    if(this->getGrid()->getElementAt(enemyPos) == this->getGrid()->getElementAt(from))
        return false;

    this->getGrid()->replaceAt(enemyPos, NO_PLAYER);
    return true;
}

bool CheckersPositionRequester::isCaptureMove(const PlayerId &playerId, const Position &from, const Position &to) const {
    // check if the move is a capture move (difference in x and y positions is 2 (2 = the move is 2 positions diagonally))
    if (std::abs(to.x - from.x) != 2 || std::abs(to.y - from.y) != 2) {
        return false;
    }

    // check if the position in between the from and to positions is occupied by the enemy player
    int enemyPlayerId = (playerId == 1) ? 2 : 1;
    int capturedPieceX = (from.x + to.x) / 2;
    int capturedPieceY = (from.y + to.y) / 2;
    if (this->getGrid()->getElementAt({capturedPieceX, capturedPieceY}) == enemyPlayerId) {
        return true;
    }

    return false;
}

bool CheckersPositionRequester::isMoveValid(const PlayerId &playerId, const Position &from, const Position &to) const {
    // check if the move is diagonal
    if (std::abs(to.x - from.x) != std::abs(to.y - from.y)) {
        return false;
    }

    // check if the move is just one step
    if (std::abs(to.x - from.x) != 1) {
        return false;
    }

    // check if player is moving backward
    if (playerId == 1 && to.x < from.x) {
        return false;
    }
    if (playerId == 2 && to.x > from.x) {
        return false;
    }
    return true;
}

