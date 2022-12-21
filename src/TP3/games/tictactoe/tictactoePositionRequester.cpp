#include "tictactoePositionRequester.hpp"

Position TicTacToePositionRequester::askForPosition(const PlayerId playerId) const
{
    std::string outputAskPlayer = "Où voulez vous placer votre pion (";
    outputAskPlayer += Player::getPlayerChar(playerId);
    outputAskPlayer += ") entre 1,1 et " + std::to_string(this->getGrid().getXSize()) + "," + std::to_string(this->getGrid().getYSize()) + " ?";

    ConsoleHandler::printLine(outputAskPlayer);

    std::vector<int> values = ConsoleHandler::readValues(2);

    int x = values[0];
    int y = values[1];

    return {(x - 1), (y - 1)};
}