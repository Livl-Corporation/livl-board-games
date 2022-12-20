#include "othello.hpp"

Position Othello::playAsComputer(const PlayerId &playerId)
{
    int col = 0, row = 0;
    return {col, row};
}

void Othello::afterPlacementAction(const PlayerId &playerId, const Position position)
{
    flipPieces(position, playerId, this->getGrid());
}

void Othello::flipPieces(const Position& pos, const PlayerId playerId, Grid<PlayerId>& grid)
{
    // Check the eight possible directions from the position that the player choose to place their token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
    };

    for (int i = 0; i < directions.size(); i++)
    {
        // Check if there are any opponent's tokens that can be flipped in this direction
        std::vector<Position> piecesToFlip = getFlippablePieces(pos, playerId, directions[i], grid);
        if (piecesToFlip.empty())
        {
            continue;
        }

        // Flip the opponent's tokens in this direction
        for (const Position& p : piecesToFlip)
        {
            grid.change(p, playerId);
        }
    }
}

std::vector<Position> Othello::getFlippablePieces(const Position& pos, const PlayerId playerId, const Position& direction, const Grid<PlayerId>& grid)
{
    std::vector<Position> pieces;

    int x = pos.x + direction.x;
    int y = pos.y + direction.y;
    while (grid.isPositionInBounds({x, y}))
    {
        PlayerId idInCell = grid.getElementAt({x, y});
        if (idInCell == playerId)
        {
            // We reached a sequence of our own tokens, so we can stop searching in this direction
            break;
        }
        else if (idInCell == NO_PLAYER)
        {
            // We reached a blank cell, so there are no flippable pieces in this direction
            return {};
        }
        else
        {
            // This is an opponent's token, so we add it to the list of flippable pieces
            pieces.push_back({x, y});
        }

        x += direction.x;
        y += direction.y;
    }

    return pieces;
}
