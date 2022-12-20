#pragma once

#include <memory>

#include "../models/position.hpp"
#include "../grid.hpp"
#include "../models/player.hpp"

class PositionRequester
{

public:
    virtual Position askForPosition(const PlayerId playerId, const Grid<PlayerId> &grid) const = 0;
};