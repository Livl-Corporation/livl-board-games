#pragma once

#include "../grid.hpp"
#include "../models/player.hpp"
#include <memory>

class GameEvaluator
{
public:
    inline void setGrid(std::unique_ptr<Grid<PlayerId>> grid) { this->grid = std::move(grid); }

    inline Grid<PlayerId> &getGrid() const { return *this->grid; }

    virtual bool hasGameEnded() = 0;

    virtual PlayerId getWinner() const = 0;

private:
    std::unique_ptr<Grid<PlayerId>> grid;
};