#include "checkersPositionRequester.hpp"

Position CheckersPositionRequester::askForPosition(const PlayerId &playerId) const {
    // Print prompt for player to select position
    ConsoleHandler::print("Player " + std::to_string(playerId) + ", select a position to move your piece from (x y): ");

    // Get input for x and y coordinates of 'from' position
    auto input = ConsoleHandler::readValues(2);
    Position from = {input[0], input[1]};

    // Check if the selected position is in bounds, not occupied and belongs to the current player
    if (!this->getGrid()->isPositionInBounds(from)) {
        ConsoleHandler::printLine("Invalid position! The position is out of bounds.");
        return askForPosition(playerId);
    }

    if (this->getGrid()->getElementAt(from) != playerId) {
        ConsoleHandler::printLine("Invalid position! The position is not occupied by your piece.");
        return askForPosition(playerId);
    }

    if (!this->getGrid()->getElementAt(from) == playerId) {
        ConsoleHandler::printLine("This is not your piece!");
    }

    // Print prompt for player to select destination position
    ConsoleHandler::print("Player " + std::to_string(playerId) + ", select a destination position for your piece (x y): ");
    input = ConsoleHandler::readValues(2);
    Position to = {input[0], input[1]};

    // Check if the destination position is in bounds and not occupied
    if (!this->getGrid()->isPositionInBounds(to)) {
        ConsoleHandler::printLine("Invalid position! The position is out of bounds.");
    }

    if (!this->getGrid()->isPositionEmpty(to)) {
        ConsoleHandler::printLine("Invalid position! The position is not empty.");
    }

    // Check if the move is valid according to checkers game rules
    if (!isMoveValid(playerId, from, to)) {
        ConsoleHandler::printLine("Invalid move! You can only move diagonally and not backward.");
        return askForPosition(playerId);
    }

    return to;
}
bool CheckersPositionRequester::isMoveValid(const PlayerId &playerId, const Position &from, const Position &to) {
    // check if the move is diagonal
    if (std::abs(to.x - from.x) != std::abs(to.y - from.y)) {
        return false;
    }

    // check if player is moving backward
    if (playerId == 1 && to.y < from.y) {
        return false;
    }
    if (playerId == 2 && to.y > from.y) {
        return false;
    }
    return true;
}

