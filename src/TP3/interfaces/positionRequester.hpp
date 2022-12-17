#pragma once

#include <memory>

#include "../models/position.hpp"
#include "../grid.hpp"

class PositionRequester
{

public:
    virtual Position askForPosition(const char playerChar, const Grid<PlayerId> &grid) const = 0;
};