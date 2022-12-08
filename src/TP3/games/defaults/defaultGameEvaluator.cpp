#include "defaultGameEvaluator.hpp"

bool DefaultGameEvaluator::hasPlayerWon(const unsigned int id, const Grid &grid)
{
    unsigned int maxConsecutive = 0;

    auto checkMaxConsecutive = [&](unsigned int startRow, unsigned int startCol, unsigned int rowStep, unsigned int colStep)
    {
        unsigned int curMaxConsecutive = 0;
        for (unsigned int row = startRow, col = startCol; row < grid.getYSize() && col < grid.getXSize(); row += rowStep, col += colStep)
        {
            if (grid.getCell({x : col, y : row}) == id)
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
    };

    // Lignes
    for (unsigned int row = 0; row < grid.getYSize(); row++)
    {
        checkMaxConsecutive(row, 0, 01, 1);
    }

    // Colonnes
    for (unsigned int col = 0; col < grid.getXSize(); col++)
    {
        checkMaxConsecutive(0, col, 1, 0);
    }

    // Diagonales
    unsigned int maxCol = grid.getXSize() - grid.getYSize();
    for (unsigned int startCol = 0; startCol <= maxCol; startCol++)
    {
        checkMaxConsecutive(0, startCol, 1, 1);
        checkMaxConsecutive(0, startCol, 1, -1);
        checkMaxConsecutive(grid.getYSize() - 1, startCol, -1, 1);
        checkMaxConsecutive(grid.getYSize() - 1, startCol, -1, -1);
    }

    return maxConsecutive >= this->consecutiveIdsToWin;
}
