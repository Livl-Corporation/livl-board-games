#pragma once

#include "grid.hpp"
#include "../models/player.hpp"
#include <memory>
#include <utility>

class GameEvaluator
{
public:
    virtual ~GameEvaluator() = default;

    inline void setGrid(std::shared_ptr<Grid<PlayerId>> _grid) { this->grid = std::move(_grid); }

    [[nodiscard]] std::shared_ptr<Grid<PlayerId>> getGrid() const { return this->grid; }

    virtual bool hasGameEnded(const PlayerId &nextPlayerId) = 0;

    [[nodiscard]] virtual PlayerId getWinner() const = 0;

private:
    std::shared_ptr<Grid<PlayerId>> grid;
};