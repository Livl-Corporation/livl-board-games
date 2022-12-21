#include "othello.hpp"
#include "othelloPositionRequester.hpp"

Position Othello::playAsComputer(const PlayerId &playerId)
{
    // Get a list of all the valid positions that the computer can place its token
    std::vector<Position> validPositions = getValidPositions(playerId);

    // Use an evaluation function to determine the best position to place the token
    Position bestPosition = getBestPosition(validPositions, playerId);

    return bestPosition;
}

std::vector<Position> Othello::getValidPositions(PlayerId playerId)
{
    std::vector<Position> validPositions;

    // Check all the cells in the grid
    for (int i = 0; i < getGrid()->getYSize(); i++)
    {
        for (int j = 0; j < getGrid()->getXSize(); j++)
        {
            Position pos{i, j};
            // If the cell is empty and there are flippable pieces in at least one direction,
            // add the position to the list of valid positions
            if (getGrid()->getElementAt(pos) == NO_PLAYER && OthelloPositionRequester::canPlaceToken(pos, playerId, *getGrid()))
            {
                validPositions.push_back(pos);
            }
        }
    }

    return validPositions;
}

Position Othello::getBestPosition(const std::vector<Position> &validPositions, PlayerId playerId)
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
            std::vector<Position> flippedPieces = getFlippablePieces(pos, playerId, direction);
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

void Othello::afterPlacementAction(const PlayerId &playerId, const Position position)
{
    flipPieces(position, playerId);
}

void Othello::flipPieces(const Position &pos, PlayerId playerId)
{
    // Check the eight possible directions from the position that the player choose to place their token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    for (auto direction : directions)
    {
        // Check if there are any opponent's tokens that can be flipped in this direction
        std::vector<Position> piecesToFlip = getFlippablePieces(pos, playerId, direction);
        if (piecesToFlip.empty())
        {
            continue;
        }

        // Flip the opponent's tokens in this direction
        for (const Position &p : piecesToFlip)
        {
            getGrid()->replaceAt(p, playerId);
        }
    }
}

std::vector<Position> Othello::getFlippablePieces(const Position &pos, PlayerId playerId, const Position &direction)
{
    std::vector<Position> pieces;

    int x = pos.x + direction.x;
    int y = pos.y + direction.y;

    while (getGrid()->isPositionInBounds({x, y}))
    {
        PlayerId idInCell = getGrid()->getElementAt({x, y});

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
