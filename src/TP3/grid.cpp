#include "grid.hpp"
#include "cell.hpp"
#include "player.hpp"
#include "functions.hpp"
#include "exceptions/out-of-bounds-exception.hpp"
#include "exceptions/occupied-cell-exception.hpp"
#include "exceptions/column-full-exception.hpp"
#include <vector>
#include <iostream>

Grid::Grid(unsigned int x, unsigned int y)
{
    this->xSize = x;
    this->ySize = y;

    // Init empty vectors
    std::vector<std::vector<int>> rowsVector;

    for (int row = 0; row < y; row++)
    {
        std::vector<int> colsVector;
        for (int col = 0; col < x; col++)
        {
            colsVector.push_back(NO_PLAYER);
        }
        rowsVector.push_back(colsVector);
    }

    this->grid = rowsVector;
}

int Grid::getCell(Cell cell) const
{
    return this->grid.at(cell.y).at(cell.x);
}

bool Grid::isCellEmpty(Cell cell) const
{
    if (!this->isCellInBounds(cell))
    {
        throw new OutOfBoundsException();
    }

    return this->getCell(cell) == NO_PLAYER;
}

bool Grid::isCellInBounds(Cell cell) const
{
    return (cell.x >= 0 && cell.x < this->xSize) && (cell.y >= 0 && cell.y < this->ySize);
}

bool Grid::isGridFull() const
{
    return getFreeCells().size() == 0;
}

bool Grid::place(Cell cell, int id)
{
    try
    {
        if (!this->isCellInBounds(cell))
        {
            throw OutOfBoundsException();
        }

        if (!this->isCellEmpty(cell))
        {
            throw OccupiedCellException();
        }

        this->grid[cell.y][cell.x] = id;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << std::endl
                  << e.what() << std::endl;
        return false;
    }
}

std::vector<Cell> Grid::getFreeCells() const
{

    std::vector<Cell> freeCells;

    for (unsigned int row = 0; row < this->ySize; row++)
    {
        for (unsigned int col = 0; col < this->xSize; col++)
        {
            Cell cell = {x : col, y : row};
            if (this->isCellEmpty(cell))
            {
                freeCells.push_back(cell);
            }
        }
    }

    return freeCells;
}

unsigned int Grid::getMaxConsecutiveIds(int id) const
{
    unsigned int maxConsecutive = 0;

    // Horizontals
    for (unsigned int row = 0; row < this->getYSize(); row++)
    {

        unsigned int rowMaxConsecutive = 0;
        for (unsigned int col = 0; col < this->getXSize(); col++)
        {
            if (this->getCell({x : col, y : row}) == id)
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
    for (unsigned int col = 0; col < this->getXSize(); col++)
    {

        unsigned int colMaxConsecutive = 0;
        for (unsigned int row = 0; row < this->getYSize(); row++)
        {
            if (this->getCell({x : col, y : row}) == id)
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
    unsigned int maxCol = this->getXSize() - this->getYSize();
    for (unsigned int startCol = 0; startCol <= maxCol; startCol++)
    {

        unsigned int upMaxConsecutive = 0;
        unsigned int downMaxConsecutive = 0;

        for (unsigned int y = 0; y < this->getYSize(); y++)
        {

            // Diagonal going down
            if (this->getCell({
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
            if (this->getCell({
                    x : (startCol + y),
                    y : (this->getYSize() - 1 - y)
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

    return maxConsecutive;
}

void Grid::displayGrid() const
{

    std::cout << std::endl;

    for (unsigned int row = 0; row < this->getYSize(); row++)
    {
        for (unsigned int col = 0; col < this->getXSize(); col++)
        {
            std::cout << getPlayerChar(this->getCell({x : col, y : row}));

            if (col < this->getXSize() - 1)
            {
                std::cout << "|";
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

unsigned int Grid::firstRowAvailableInCol(unsigned int col) const
{

    Cell cell{x : col, y : (this->getYSize() - 1)};

    while (!this->isCellEmpty(cell))
    {
        if (cell.y == 0)
        {
            throw ColumnFullException();
        }
        else
        {
            cell.y--;
        }
    }

    return cell.y;
}