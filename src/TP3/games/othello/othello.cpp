#include "othello.hpp"
#include "othelloPositionRequester.hpp"

Position Othello::playAsComputer(const PlayerId &playerId)
{
    // Get a list of all the valid positions that the computer can place its token
    std::vector<Position> validPositions = OthelloGameEvaluator::getValidPositions(playerId, *getGrid());

    // Use an evaluation function to determine the best position to place the token
    Position bestPosition = OthelloGameEvaluator::getBestPosition(validPositions, playerId, *getGrid());

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
        std::vector<Position> piecesToFlip = OthelloGameEvaluator::getFlippablePieces(pos, playerId, direction, *getGrid());
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