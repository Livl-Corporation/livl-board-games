#include "othelloPositionRequester.hpp"

Position OthelloPositionRequester::askForPosition(const PlayerId playerId) const
{
    while (true)
    {
        std::string outputAskPlayer = "Où voulez vous placer votre pion (";
        outputAskPlayer += Player::getPlayerChar(playerId);
        outputAskPlayer += ") entre 1,1 et " + std::to_string(this->getGrid()->getXSize()) + "," + std::to_string(this->getGrid()->getYSize()) + " ?";

        ConsoleHandler::printLine(outputAskPlayer);

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

        std::cout << "Invalid position. Please try again." << std::endl;
    }
}