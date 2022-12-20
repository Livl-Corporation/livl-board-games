#include "tictactoePositionRequester.hpp"

Position TicTacToePositionRequester::askForPosition(const PlayerId playerId, const Grid<PlayerId> &grid) const
{
    std::string outputAskPlayer = "Où voulez vous placer votre pion (";
    outputAskPlayer += Player::getPlayerChar(playerId);
    outputAskPlayer += ") entre 1,1 et " + std::to_string(grid.getXSize()) + "," + std::to_string(grid.getYSize()) + " ?";

    ConsoleHandler::printLine(outputAskPlayer);

    // Read two values using the readValues function
    std::vector<int> values = ConsoleHandler::readValues(2);

    // Extract the row and col values from the vector
    int x = values[0];
    int y = values[1];

    return {(x - 1), (y - 1)};
}