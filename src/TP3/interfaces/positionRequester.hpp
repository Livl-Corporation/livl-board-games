#pragma once

#include <memory>

#include "../models/position.hpp"
#include "../grid.hpp"
#include "../models/player.hpp"

class PositionRequester
{

public:
    inline void setGrid(std::shared_ptr<Grid<PlayerId>> grid) { this->grid = grid; }

    std::shared_ptr<Grid<PlayerId>> getGrid() const
    {
        return this->grid;
    }

    virtual Position askForPosition(const PlayerId playerId) const = 0;

private:
    std::shared_ptr<Grid<PlayerId>> grid;
};