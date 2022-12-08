#pragma once

#include "../models/cell.hpp"
#include "../grid.hpp"

class CellRequester
{

public:
    /**
     * @brief Ask the user for the cell in wich he has to place his id
     *
     * @param playerChar
     * @return Cell
     */
    virtual Cell askForCell(const char playerChar, const Grid &grid) = 0;

protected:
};