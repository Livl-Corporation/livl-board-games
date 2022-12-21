#include "othelloPositionRequester.hpp"

Position OthelloPositionRequester::askForPosition(const PlayerId playerId) const
{
    while (true)
    {
        ConsoleHandler::print("Place your token (" + std::string(1, Player::getPlayerChar(playerId)) + ") between (1,1 to " + std::to_string(this->getGrid()->getYSize()) + "," + std::to_string(this->getGrid()->getXSize()) + ") : ");

        std::vector<int> values = ConsoleHandler::readValues(2);

        // Extract the row and col values from the vector
        int row = values[0];
        int col = values[1];

        Position pos{col - 1, row - 1};
        if (this->getGrid()->isPositionInBounds(pos) && this->getGrid()->isPositionEmpty(pos))
        {
            // Check if the position is valid according to the rules of the Reversi game
            if (OthelloPositionRequester::canPlaceToken(pos, playerId, *this->getGrid()))
            {
                return pos;
            }
        }
        ConsoleHandler::printLine("Oops. Invalid position (" + std::to_string(pos.y+1) + "," + std::to_string(pos.x+1) + "). Please try again !");
    }
}

bool OthelloPositionRequester::canPlaceToken(const Position &pos, const PlayerId playerId, const Grid<PlayerId> &grid)
{
    // Check the eight possible directions from the position that the player choose to place his token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    for (auto direction : directions)
    {
        int x = pos.x + direction.x;
        int y = pos.y + direction.y;
        bool foundOpponent = false;
        while (grid.isPositionInBounds({x, y}))
        {
            int idInCell = grid.getElementAt({x, y});
            if (idInCell == NO_PLAYER)
            {
                break;
            }
            else if (idInCell != playerId)
            {
                foundOpponent = true;
            }
            else if (idInCell == playerId && foundOpponent)
            {
                return true;
            }
            else
            {
                // We reached a blank cell or a sequence of our own tokens, so we can stop searching in this direction
                break;
            }
            x += direction.x;
            y += direction.y;
        }
    }
    return false;
}
