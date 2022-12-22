#pragma once

#include <memory>
#include <utility>

#include "../models/position.hpp"
#include "grid.hpp"
#include "../models/player.hpp"

class PositionRequester
{

public:
    virtual ~PositionRequester() = default;

    inline void setGrid(std::shared_ptr<Grid<PlayerId>> _grid) { this->grid = std::move(_grid); }

    [[nodiscard]] std::shared_ptr<Grid<PlayerId>> getGrid() const { return this->grid; }

    [[nodiscard]] virtual Position askForPosition(const PlayerId &playerId) const = 0;

private:
    std::shared_ptr<Grid<PlayerId>> grid;
};