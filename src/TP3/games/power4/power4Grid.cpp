#include "power4Grid.hpp"

unsigned int Power4Grid::firstRowAvailableInCol(unsigned int col) const
{
    Position position{x : col, y : (this->getYSize() - 1)};

    while (!this->isPositionEmpty(position))
    {

        if (position.y == 0)
        {
            // If there is no row available in this col, throw an exception & exit function
            throw ColumnFullException();
        }
        else
        {
            position.y--;
        }
    }

    return position.y;
}