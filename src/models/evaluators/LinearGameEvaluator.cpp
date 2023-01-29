//
// Created by Franck GUTMANN on 29/01/2023.
//

#include "LinearGameEvaluator.h"
#include "models/Grid.cpp"

bool LinearGameEvaluator::hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) {
    if (this->hasPlayerWon(grid, 1))
    {
        this->winner = 1;
    }
    else if (this->hasPlayerWon(grid, 2))
    {
        this->winner = 2;
    }

    return this->winner != NO_PLAYER || grid.isFull();
}

PlayerId LinearGameEvaluator::getWinner(const Grid<Token> &grid) const
{
    return winner;
}

bool LinearGameEvaluator::hasPlayerWon(const Grid<Token> &grid, const PlayerId &id) const
{
    unsigned int maxConsecutive = 0;

    checkRows(grid, id, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    checkColumns(grid, id, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    checkDiagonals(grid, id, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    return false;
}

void LinearGameEvaluator::checkRows(const Grid<Token> &grid, const PlayerId &id, unsigned int &maxConsecutive) const
{
    for (int row = 0; row < grid.getYSize(); row++)
    {
        checkMaxConsecutive(grid, id, row, 0, 0, 1, maxConsecutive);
    }
}

void LinearGameEvaluator::checkColumns(const Grid<Token> &grid, const PlayerId &id, unsigned int &maxConsecutive) const
{
    for (int col = 0; col < grid.getXSize(); col++)
    {
        checkMaxConsecutive(grid, id, 0, col, 1, 0, maxConsecutive);
    }
}

void LinearGameEvaluator::checkDiagonals(const Grid<Token> &grid, const PlayerId &id, unsigned int &maxConsecutive) const
{
    unsigned int maxCol = grid.getXSize() - grid.getYSize();
    for (int startCol = 0; startCol <= maxCol; startCol++)
    {
        checkMaxConsecutive(grid, id, 0, startCol, 1, 1, maxConsecutive);
        checkMaxConsecutive(grid, id, 0, startCol, 1, -1, maxConsecutive);
        checkMaxConsecutive(grid, id, grid.getYSize() - 1, startCol, -1, 1, maxConsecutive);
        checkMaxConsecutive(grid, id, grid.getYSize() - 1, startCol, -1, -1, maxConsecutive);
    }
}

void LinearGameEvaluator::checkMaxConsecutive(const Grid<Token> &grid, const PlayerId &id, int startRow, int startCol, int rowStep, int colStep, unsigned int &maxConsecutive) const
{
    unsigned int curMaxConsecutive = 0;
    for (int row = startRow, col = startCol; row < grid.getYSize() && col < grid.getXSize() && row >= 0 && col >= 0; row += rowStep, col += colStep)
    {
        if (grid.getElementAt({col, row}).getPlayerId() == id)
        {
            curMaxConsecutive++;
        }
        else if (curMaxConsecutive >= this->consecutiveIdsToWin)
        {
            break;
        }
        else
        {
            curMaxConsecutive = 0;
        }
    }
    if (curMaxConsecutive > maxConsecutive)
    {
        maxConsecutive = curMaxConsecutive;
    }
}