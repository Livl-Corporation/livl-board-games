#include "othelloPositionRequester.hpp"

Position OthelloPositionRequester::askForPosition(const char playerChar, const Grid<PlayerId> &grid) const
{
    while (true)
    {
        std::string outputAskPlayer = "Où voulez vous placer votre pion (";
        outputAskPlayer += playerChar;
        outputAskPlayer += ") entre 1,1 et " + std::to_string(grid.getXSize()) + "," + std::to_string(grid.getYSize()) + " ?";

        ConsoleHandler::printLine(outputAskPlayer);

        unsigned int row, col;
        ConsoleHandler::readTwoValues(row, col);

        Position pos{ col - 1, row - 1 };
        if (grid.isPositionInBounds(pos) && grid.isPositionEmpty(pos))
        {
            // Check if the position is valid according to the rules of the Reversi game
            char opponentChar = (playerChar == 'X') ? 'O' : 'X';
            if (canPlaceToken(pos, playerChar, opponentChar, grid))
            {
                return pos;
            }
        }

        std::cout << "Invalid position. Please try again." << std::endl;
    }
}

bool OthelloPositionRequester::canPlaceToken(const Position &pos, char playerChar, char opponentChar, Grid<PlayerId> grid) const
{
    // Check the eight possible directions from the position that the player choose to place his token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<std::pair<int, int>> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
    };

    for (int i = 0; i < 8; i++)
    {
        unsigned int x = pos.x + directions[i].first;
        unsigned int y = pos.y + directions[i].second;
        bool foundOpponent = false;
        while (grid.isPositionInBounds({ x, y }))
        {
            char cell = Player::getPlayerChar(grid.getElementAt({ x, y }));
            if (cell == opponentChar)
            {
                foundOpponent = true;
            }
            else if (cell == playerChar && foundOpponent)
            {
                return true;
            }
            else
            {
                // We reached a blank cell or a sequence of our own tokens, so we can stop searching in this direction
                break;
            }
            x += directions[i].first;
            y += directions[i].second;
        }
    }
    return false;
}