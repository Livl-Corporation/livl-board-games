#pragma once

#include <memory>
#include <utility>

#include "../models/position.hpp"
#include "grid.hpp"
#include "../models/player.hpp"
#include "gameInterface.h"

class PositionRequester
{

public:
    virtual ~PositionRequester() = default;

    inline void setGrid(std::shared_ptr<Grid<PlayerId>> _grid) { this->grid = std::move(_grid); }

    inline void setGameInterface(std::shared_ptr<GameInterface> _gameInterface) { this->gameInterface = std::move(_gameInterface); }

    [[nodiscard]] std::shared_ptr<Grid<PlayerId>> getGrid() const { return this->grid; }

    [[nodiscard]] std::shared_ptr<GameInterface> getGameInterface() const { return this->gameInterface; }

    [[nodiscard]] virtual Position askForPosition(const PlayerId &playerId) const = 0;

private:
    std::shared_ptr<Grid<PlayerId>> grid;
    std::shared_ptr<GameInterface> gameInterface;
};