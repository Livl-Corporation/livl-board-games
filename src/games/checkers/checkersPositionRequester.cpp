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
        break;
    }

    // Remove the initial position from the grid if the move is valid
    this->getGrid()->replaceAt(from, NO_PLAYER);

    return position;
}

bool CheckersPositionRequester::isMoveValid(const PlayerId &playerId, const Position &from, const Position &to) const {
    // check if the move is diagonal
    if (std::abs(to.x - from.x) != std::abs(to.y - from.y)) {
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

