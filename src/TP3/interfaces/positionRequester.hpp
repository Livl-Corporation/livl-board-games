#pragma once

#include <memory>

#include "../models/position.hpp"
#include "../grid.hpp"
#include "../models/player.hpp"

class PositionRequester
{

public:
    inline void setGrid(std::unique_ptr<Grid<PlayerId>> grid) { this->grid = std::move(grid); }

    inline Grid<PlayerId> &getGrid() const { return *this->grid; }

    virtual Position askForPosition(const PlayerId playerId) const = 0;

private:
    std::unique_ptr<Grid<PlayerId>> grid;
};