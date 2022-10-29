#include "grid.hpp"
#include "symbol.hpp"
#include "cell.hpp"
#include "exceptions/out-of-bounds-exception.hpp"
#include "exceptions/occupied-cell-exception.hp"
#include <vector>
#include <iostream>

Grid::Grid(unsigned int x, unsigned int y)
{
    this->xSize = x;
    this->ySize = y;

    // Init empty vectors
    std::vector<std::vector<Symbol>> rowsVector = new std::vector();

    for (int row = 0; row < y; row++)
    {
        std::vector<Symbol> colsVector = new std::vector();
        for (int col = 0; col < x; col++)
        {
            colsVector.push_back(Symbol::empty);
        }
        rowsVector.push_back(colsVector);
    }
}

Symbol Grid::getCell(Cell cell) const
{
    return this->grid.at(cell.y).at(cell.x);
}

bool Grid::isCellEmpty(Cell cell) const
{
    if (!this->isCellInBounds(cell))
    {
        throw new OutOfBoundsException();
    }

    return this->getCell(cell).getSymbol() == Symbol::empty.getSymbol();
}

bool Grid::isCellInBounds(Cell cell) const
{
    return (cell.x >= 0 && cell.x < this->xSize) && (cell.y >= 0 && cell.y < this->ySize);
}

bool Grid::placeSymbol(Cell cell, Symbol symbol)
{
    if (!this->isCellInBounds(cell))
    {
        throw new OutOfBoundsException();
    }

    if (!this->isCellEmpty(cell))
    {
        throw new OccupiedCellException();
    }

    this->grid.at(cell.y).at(cell.x) = symbol;
}

std::vector<Cell> Grid::getFreeCells() const
{

    std::vector<Cell> freeCells = new std::vector();

    for (int row = 0; row < this->ySize; row++)
    {
        for (int col = 0; col < this->xSize; col++)
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

unsigned int Grid::getMaxConsecutiveSymbols(Symbol symbol) const
{
}

void Grid::displayGrid() const
{

    for (unsigned int row = 0; row < this->ySize; row++)
    {
        for (unsigned int col = 0; col < this->xSize; col++)
        {
            std::cout << this->getCell({x : col, y : row}).getSymbol();

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