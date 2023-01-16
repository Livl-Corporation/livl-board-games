#include "othelloPositionRequester.hpp"

Position OthelloPositionRequester::askForPosition(const PlayerId &playerId) const
{
    while (true)
    {
        InteractionsProvider::gameInterface()->printInfo("Place your token (" + std::string(1, Player::getPlayerChar(playerId)) + ") between (1,1 to " + std::to_string(this->getGrid()->getYSize()) + "," + std::to_string(this->getGrid()->getXSize()) + ") : ");

        std::vector<int> values = ConsoleHandler::readValues(2);

        // Extract the row and col values from the vector
        int row = values[0];
        int col = values[1];

        Position pos{col - 1, row - 1};
        if (this->getGrid()->isPositionInBounds(pos) && this->getGrid()->isPositionEmpty(pos))
        {
            // Check if the position is valid according to the rules of the Reversi game
            if (OthelloGameEvaluator::canPlaceToken(pos, playerId, *this->getGrid()))
            {
                return pos;
            }
        }
        InteractionsProvider::gameInterface()->printError("Oops. Invalid position (" + std::to_string(pos.y + 1) + "," + std::to_string(pos.x + 1) + "). Please try again !");
    }
}