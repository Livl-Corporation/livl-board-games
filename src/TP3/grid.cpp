#include "grid.hpp"
#include "cell.hpp"
#include "player.hpp"
#include "exceptions/out-of-bounds-exception.hpp"
#include "exceptions/occupied-cell-exception.hp"
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

bool Grid::isGridFull() const {
    return getFreeCells().size() == 0;
}

bool Grid::place(Cell cell, int id)
{
    if (!this->isCellInBounds(cell))
    {
        throw new OutOfBoundsException();
    }

    if (!this->isCellEmpty(cell))
    {
        throw new OccupiedCellException();
    }

    this->grid.at(cell.y).at(cell.x) = id;
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

    // TODO : Implement method

    // Horizontals

    // Verticals

    // Diagonals going up

    // Diagonals going down

    return maxConsecutive;

}

void Grid::displayGrid() const
{

    for (unsigned int row = 0; row < this->ySize; row++)
    {
        for (unsigned int col = 0; col < this->xSize; col++)
        {
            std::cout << this->getCell({x : col, y : row});

            if (col < this->xSize - 1)
            {
                std::cout << "|";
            }
        }

        std::cout << std::endl;

        if (row < this->ySize - 1)
        {
            std::cout << "-----";
        }
    }
}