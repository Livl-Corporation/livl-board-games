#include "defaultGameEvaluator.hpp"

bool DefaultGameEvaluator::hasPlayerWon(const unsigned int id, const Grid &grid)
{

    unsigned int maxConsecutive = 0;

    // Horizontals
    for (unsigned int row = 0; row < grid.getYSize(); row++)
    {

        unsigned int rowMaxConsecutive = 0;
        for (unsigned int col = 0; col < grid.getXSize(); col++)
        {
            if (grid.getCell({x : col, y : row}) == id)
            {
                rowMaxConsecutive++;
            }
            else
            {
                rowMaxConsecutive = 0;
            }
        }

        if (rowMaxConsecutive > maxConsecutive)
        {
            maxConsecutive = rowMaxConsecutive;
        }
    }

    // Verticals
    for (unsigned int col = 0; col < grid.getXSize(); col++)
    {

        unsigned int colMaxConsecutive = 0;
        for (unsigned int row = 0; row < grid.getYSize(); row++)
        {
            if (grid.getCell({x : col, y : row}) == id)
            {
                colMaxConsecutive++;
            }
            else
            {
                colMaxConsecutive = 0;
            }
        }

        if (colMaxConsecutive > maxConsecutive)
        {
            maxConsecutive = colMaxConsecutive;
        }
    }

    // Diagonals
    unsigned int maxCol = grid.getXSize() - grid.getYSize();
    for (unsigned int startCol = 0; startCol <= maxCol; startCol++)
    {

        unsigned int upMaxConsecutive = 0;
        unsigned int downMaxConsecutive = 0;

        for (unsigned int y = 0; y < grid.getYSize(); y++)
        {

            // Diagonal going down
            if (grid.getCell({
                    x : (startCol + y),
                    y : y
                }) == id)
            {
                downMaxConsecutive++;
            }
            else
            {
                downMaxConsecutive = 0;
            }

            // Diagonal going up
            if (grid.getCell({
                    x : (startCol + y),
                    y : (grid.getYSize() - 1 - y)
                }) == id)
            {
                upMaxConsecutive++;
            }
            else
            {
                upMaxConsecutive = 0;
            }
        }

        if (upMaxConsecutive > maxConsecutive)
        {
            maxConsecutive = upMaxConsecutive;
        }

        if (downMaxConsecutive > maxConsecutive)
        {
            maxConsecutive = downMaxConsecutive;
        }
    }

    return maxConsecutive >= this->consecutiveIdsToWin;
}