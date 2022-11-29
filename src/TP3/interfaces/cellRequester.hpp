#pragma once

#include "../models/cell.hpp"
#include "../grid.hpp"

class CellRequester
{

public:
    /**
     * @brief Construct a new Cell Requester object
     *
     * @param grid
     */
    CellRequester(const Grid &grid) : grid(grid) {}

    /**
     * @brief Ask the user for the cell in wich he has to place his id
     *
     * @param playerChar
     * @return Cell
     */
    virtual Cell askForCell(const char playerChar) = 0;

protected:
    Grid grid;
};