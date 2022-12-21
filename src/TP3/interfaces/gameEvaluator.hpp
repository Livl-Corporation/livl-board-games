#pragma once

#include "../grid.hpp"
#include "../models/player.hpp"
#include <memory>

class GameEvaluator
{
public:
    inline void setGrid(std::shared_ptr<Grid<PlayerId>> grid) { this->grid = grid; }

    std::shared_ptr<Grid<PlayerId>> getGrid() const { return this->grid; }

    virtual bool hasGameEnded() = 0;

    virtual PlayerId getWinner() const = 0;

private:
    std::shared_ptr<Grid<PlayerId>> grid;
};