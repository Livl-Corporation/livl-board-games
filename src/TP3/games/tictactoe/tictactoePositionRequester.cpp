#include "tictactoePositionRequester.hpp"

Position TicTacToePositionRequester::askForPosition(const char playerChar, const Grid<PlayerId> &grid) const
{
    std::string outputAskPlayer = "Où voulez vous placer votre pion (";
    outputAskPlayer += playerChar;
    outputAskPlayer += ") entre 1,1 et " + std::to_string(grid.getXSize()) + "," + std::to_string(grid.getYSize()) + " ?";

    ConsoleHandler::printLine(outputAskPlayer);

    unsigned int x, y;
    ConsoleHandler::readTwoValues(x, y);

    return {(x - 1), (y - 1)};
}