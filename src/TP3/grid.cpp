#include "grid.hpp"

int Grid::getCell(const Cell &cell) const
{
    return this->grid.at(cell.y).at(cell.x);
}

bool Grid::isCellEmpty(const Cell &cell) const
{

    if (!this->isCellInBounds(cell))
    {
        throw new OutOfBoundsException();
    }

    return this->getCell(cell) == NO_PLAYER;
}

bool Grid::isCellInBounds(const Cell &cell) const
{
    return (cell.x >= 0 && cell.x < this->xSize) && (cell.y >= 0 && cell.y < this->ySize);
}

bool Grid::isGridFull() const
{
    return getFreeCells().size() == 0;
}

bool Grid::place(const Cell &cell, const unsigned int id)
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

void Grid::displayGrid() const
{

    std::cout << std::endl;

    for (unsigned int row = 0; row < this->getYSize(); row++)
    {
        for (unsigned int col = 0; col < this->getXSize(); col++)
        {
            std::cout << Player::getPlayerChar(this->getCell({x : col, y : row}));

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
            // If there is no row available in this col, throw an exception & exit function
            throw ColumnFullException();
        }
        else
        {
            cell.y--;
        }
    }

    return cell.y;
}