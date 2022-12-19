#include "othelloPositionRequester.hpp"

Position OthelloPositionRequester::askForPosition(const char playerChar, const Grid<PlayerId> &grid) const
{
    while (true)
    {
        std::cout << "Player " << playerChar << ", enter the row and column where you want to place your token (e.g. 3 4): ";
        int row, col;
        std::cin >> row >> col;

        Position pos{ static_cast<unsigned int>(col - 1), static_cast<unsigned int>(row - 1) };
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

bool OthelloPositionRequester::canPlaceToken(const Position &pos, char playerChar, char opponentChar, const Grid<PlayerId> &grid) const
{
    // Check the eight possible directions from the position that the player choose to place his token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<int> dx{ -1, -1, -1, 0, 1, 1,  1,  0 };
    static const std::vector<int> dy{ -1,  0,  1, 1, 1, 0, -1, -1 };

    for (int i = 0; i < 8; i++)
    {
        int x = pos.x + dx[i];
        int y = pos.y + dy[i];
        bool foundOpponent = false;
        while (grid.isPositionInBounds({ static_cast<unsigned int>(x), static_cast<unsigned int>(y) }))
        {
            char cell = Player::getPlayerChar(grid.getElementAt({ static_cast<unsigned int>(x), static_cast<unsigned int>(y) }));
            if (cell == opponentChar)
            {
                foundOpponent = true;
            }
            else if (cell == playerChar && foundOpponent)
            {
                // We found a sequence of opponent's tokens that can be flipped
                return true;
            }
            else
            {
                // We reached a blank cell or a sequence of our own tokens, so we can stop searching in this direction
                break;
            }
            x += dx[i];
            y += dy[i];
        }
    }
    return false;
}