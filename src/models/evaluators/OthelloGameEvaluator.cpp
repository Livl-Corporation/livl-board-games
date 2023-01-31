//
// Created by Franck GUTMANN on 30/01/2023.
//

#include "OthelloGameEvaluator.h"

bool OthelloGameEvaluator::hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId)
{
    std::vector<Position> ids = OthelloGameEvaluator::getValidPositions(nextPlayerId, grid);
    return grid.isFull() || ids.empty();
}

PlayerId OthelloGameEvaluator::getWinner(const Grid<Token> &grid) const
{
    // Initialize counters for the number of tokens placed by each player
    int player1Tokens = 0;
    int player2Tokens = 0;

    // Iterate through the cells in the grid and count the number of tokens placed by each player
    for (int i = 0; i < grid.getRowCount(); i++)
    {
        for (int j = 0; j < grid.getColCount(); j++)
        {
            PlayerId idInCell = grid.getElementAt({i, j})->getPlayerId();
            if (idInCell == 1)
            {
                player1Tokens++;
            }
            else if (idInCell == 2)
            {
                player2Tokens++;
            }
        }
    }

    // Return the player with the most tokens as the winner
    if (player1Tokens > player2Tokens)
    {
        return 1;
    }
    else if (player2Tokens > player1Tokens)
    {
        return 2;
    }
    else
    {
        // In case of a tie, return NO_PLAYER
        return NO_PLAYER;
    }
}

bool OthelloGameEvaluator::canPlaceToken(const Position &pos, PlayerId playerId, const Grid<Token> &grid)
{
    // Check the eight possible directions from the position that the player choose to place his token
    // (left-up, up, right-up, right, right-down, down, left-down, left)
    static const std::vector<Position> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    for (auto direction : directions)
    {
        int col = pos.col + direction.col;
        int row = pos.row + direction.row;
        bool foundOpponent = false;
        while (grid.isPositionInBounds({row, col}))
        {
            PlayerId idInCell = grid.getElementAt({row, col})->getPlayerId();
            if (idInCell == NO_PLAYER)
            {
                break;
            }

            if (idInCell != playerId)
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

            col += direction.col;
            row += direction.row;
        }
    }
    return false;
}

std::vector<Position> OthelloGameEvaluator::getValidPositions(const PlayerId &playerId, const Grid<Token> &grid)
{
    std::vector<Position> validPositions;

    // Check all the cells in the grid
    for (int i = 0; i < grid.getRowCount(); i++)
    {
        for (int j = 0; j < grid.getColCount(); j++)
        {
            Position pos{i, j};
            // If the cell is empty and there are flippable pieces in at least one direction,
            // add the position to the list of valid positions
            if (grid.getElementAt(pos)->getPlayerId() == NO_PLAYER && OthelloGameEvaluator::canPlaceToken(pos, playerId, grid))
            {
                validPositions.push_back(pos);
            }
        }
    }

    return validPositions;
}

Position OthelloGameEvaluator::getBestPosition(const std::vector<Position> &validPositions, const PlayerId &playerId, const Grid<Token> &grid)
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

std::vector<Position> OthelloGameEvaluator::getFlippablePieces(const Position &pos, const PlayerId &playerId, const Position &direction, const Grid<Token> &grid)
{
    std::vector<Position> pieces;

    int col = pos.col + direction.col;
    int row = pos.row + direction.row;

    while (grid.isPositionInBounds({row, col}))
    {
        PlayerId idInCell = grid.getElementAt({row, col})->getPlayerId();

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
            pieces.push_back({row, col});
        }

        col += direction.col;
        row += direction.row;
    }

    return pieces;
}
