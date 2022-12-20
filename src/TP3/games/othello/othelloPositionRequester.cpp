#include "othelloPositionRequester.hpp"

Position OthelloPositionRequester::askForPosition(const PlayerId playerId, const Grid<PlayerId> &grid) const
{
    while (true)
    {
        std::string outputAskPlayer = "Où voulez vous placer votre pion (";
        outputAskPlayer += Player::getPlayerChar(playerId);
        outputAskPlayer += ") entre 1,1 et " + std::to_string(grid.getXSize()) + "," + std::to_string(grid.getYSize()) + " ?";

        ConsoleHandler::printLine(outputAskPlayer);

        // Read two values using the readValues function
        std::vector<int> values = ConsoleHandler::readValues(2);

        // Extract the row and col values from the vector
        int row = values[0];
        int col = values[1];

        Position pos{col - 1, row - 1};
        if (grid.isPositionInBounds(pos) && grid.isPositionEmpty(pos))
        {
            // Check if the position is valid according to the rules of the Reversi game
            if (canPlaceToken(pos, playerId, grid))
            {
                return pos;
            }
        }

        std::cout << "Invalid position. Please try again." << std::endl;
    }
}

bool OthelloPositionRequester::canPlaceToken(const Position &pos, const PlayerId playerId, const Grid<PlayerId> &grid)
{
    // Check the eight possible directions from the position that the player choose to place his token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
    };

    for (int i = 0; i < directions.size(); i++)
    {
        int x = pos.x + directions[i].x;
        int y = pos.y + directions[i].y;
        bool foundOpponent = false;
        while (grid.isPositionInBounds({x, y}))
        {
            int idInCell = grid.getElementAt({x, y});
            if(idInCell == NO_PLAYER){
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
            x += directions[i].x;
            y += directions[i].y;
        }
    }
    return false;
}

