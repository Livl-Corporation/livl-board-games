#pragma once

#include <memory>

#include "../models/position.hpp"
#include "../grid.hpp"

class PositionRequester
{

public:
    /**
     * @brief Ask the user for the position in wich he has to place his id
     *
     * @param playerChar
     * @return Position
     */
    virtual Position askForPosition(const char playerChar, const Grid<PlayerId> &grid) const = 0;
};