#pragma once

#include "../../interfaces/grid.hpp"
#include "../../models/player.hpp"

class CheckersGrid : public Grid<PlayerId>
{
public:
    CheckersGrid() : Grid(xSize, ySize, NO_PLAYER){};
    explicit CheckersGrid(const Grid<PlayerId> &other) : Grid<PlayerId>(other) {}

    static constexpr int xSize = 8;
    static constexpr int ySize = 8;
};


