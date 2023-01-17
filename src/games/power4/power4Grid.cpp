#include "power4Grid.hpp"
#include "../../shared/exceptions/column-full-exception.hpp"

int Power4Grid::firstRowAvailableInCol(int col) const
{
    Position position{col, (this->getYSize() - 1)};

    while (!isPositionEmpty(position))
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