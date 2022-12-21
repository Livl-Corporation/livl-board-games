#include "tictactoePositionRequester.hpp"

Position TicTacToePositionRequester::askForPosition(const PlayerId playerId) const
{
    ConsoleHandler::print("Place your token (" + std::string(1, Player::getPlayerChar(playerId)) + ") between (1,1 to " + std::to_string(this->getGrid()->getYSize()) + "," + std::to_string(this->getGrid()->getXSize()) + ") : ");

    std::vector<int> values = ConsoleHandler::readValues(2);

    int y = values[0];
    int x = values[1];

    return {(x - 1), (y - 1)};
}