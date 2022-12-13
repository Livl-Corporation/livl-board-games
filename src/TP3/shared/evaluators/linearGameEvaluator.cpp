#include "linearGameEvaluator.hpp"

bool LinearGameEvaluator::hasPlayerWon(const PlayerId id, const Grid &grid) const
{
    unsigned int maxConsecutive = 0;

    // Lignes
    checkRows(id, grid, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    // Colonnes
    checkColumns(id, grid, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    // Diagonales
    checkDiagonals(id, grid, maxConsecutive);
    if (maxConsecutive >= this->consecutiveIdsToWin)
        return true;

    return false;
}

void LinearGameEvaluator::checkRows(const PlayerId id, const Grid &grid, unsigned int &maxConsecutive) const
{
    for (unsigned int row = 0; row < grid.getYSize(); row++)
    {
        checkMaxConsecutive(id, grid, row, 0, 0, 1, maxConsecutive);
    }
}

void LinearGameEvaluator::checkColumns(const PlayerId id, const Grid &grid, unsigned int &maxConsecutive) const
{
    for (unsigned int col = 0; col < grid.getXSize(); col++)
    {
        checkMaxConsecutive(id, grid, 0, col, 1, 0, maxConsecutive);
    }
}

void LinearGameEvaluator::checkDiagonals(const PlayerId id, const Grid &grid, unsigned int &maxConsecutive) const
{
    unsigned int maxCol = grid.getXSize() - grid.getYSize();
    for (unsigned int startCol = 0; startCol <= maxCol; startCol++)
    {
        checkMaxConsecutive(id, grid, 0, startCol, 1, 1, maxConsecutive);
        checkMaxConsecutive(id, grid, 0, startCol, 1, -1, maxConsecutive);
        checkMaxConsecutive(id, grid, grid.getYSize() - 1, startCol, -1, 1, maxConsecutive);
        checkMaxConsecutive(id, grid, grid.getYSize() - 1, startCol, -1, -1, maxConsecutive);
    }
}

void LinearGameEvaluator::checkMaxConsecutive(const PlayerId id, const Grid &grid, unsigned int startRow, unsigned int startCol, unsigned int rowStep, unsigned int colStep, unsigned int &maxConsecutive) const
{
    unsigned int curMaxConsecutive = 0;
    for (unsigned int row = startRow, col = startCol; row < grid.getYSize() && col < grid.getXSize(); row += rowStep, col += colStep)
    {
        if (grid.getPosition({x : col, y : row}) == id)
        {
            curMaxConsecutive++;
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
