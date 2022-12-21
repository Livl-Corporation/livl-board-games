#include "othelloGameEvaluator.hpp"

bool OthelloGameEvaluator::hasGameEnded(const PlayerId nextPlayerId)
{
    return this->getGrid()->isFull() || OthelloGameEvaluator::getValidPositions(nextPlayerId, *this->getGrid()).empty();
}

PlayerId OthelloGameEvaluator::getWinner() const
{
    return 0;
}

bool OthelloGameEvaluator::canPlaceToken(const Position &pos, const PlayerId playerId, const Grid<PlayerId> &grid)
{
    // Check the eight possible directions from the position that the player choose to place his token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    for (int i = 0; i < directions.size(); i++)
    {
        int x = pos.x + directions[i].x;
        int y = pos.y + directions[i].y;
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
            x += directions[i].x;
            y += directions[i].y;
        }
    }
    return false;
}

std::vector<Position> OthelloGameEvaluator::getValidPositions(PlayerId playerId, const Grid<PlayerId> &grid)
{
    std::vector<Position> validPositions;

    // Check all the cells in the grid
    for (int i = 0; i < grid.getYSize(); i++)
    {
        for (int j = 0; j < grid.getXSize(); j++)
        {
            Position pos{i, j};
            // If the cell is empty and there are flippable pieces in at least one direction,
            // add the position to the list of valid positions
            if (grid.getElementAt(pos) == NO_PLAYER && OthelloGameEvaluator::canPlaceToken(pos, playerId, grid))
            {
                validPositions.push_back(pos);
            }
        }
    }

    return validPositions;
}

Position OthelloGameEvaluator::getBestPosition(const std::vector<Position> &validPositions, PlayerId playerId, const Grid<PlayerId> &grid)
{
    // Start with the first position in the list
    Position bestPosition = validPositions[0];
    size_t maxFlippedPieces = 0;

    static const std::vector<Position> directions{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    // Iterate through the list of valid positions, and choose the position that flips the most pieces
    for (const Position &pos : validPositions)
    {
        for (auto direction : directions)
        {
            std::vector<Position> flippedPieces = OthelloGameEvaluator::getFlippablePieces(pos, playerId, direction, grid);
            size_t numFlippedPieces = flippedPieces.size();
            if (numFlippedPieces > maxFlippedPieces)
            {
                bestPosition = pos;
                maxFlippedPieces = numFlippedPieces;
            }
        }
    }

    return bestPosition;
}

std::vector<Position> OthelloGameEvaluator::getFlippablePieces(const Position &pos, PlayerId playerId, const Position &direction, const Grid<PlayerId> &grid)
{
    std::vector<Position> pieces;

    int x = pos.x + direction.x;
    int y = pos.y + direction.y;

    while (grid.isPositionInBounds({x, y}))
    {
        PlayerId idInCell = grid.getElementAt({x, y});

        // We reached a sequence of our own tokens, so we can stop searching in this direction
        if (idInCell == playerId)
        {
            break;
        }
        // We reached a blank cell, so there are no flippable pieces in this direction
        else if (idInCell == NO_PLAYER)
        {
            return {};
        }
        else // This is an opponent's token, so we add it to the list of flippable pieces
        {
            pieces.push_back({x, y});
        }

        x += direction.x;
        y += direction.y;
    }

    return pieces;
}
