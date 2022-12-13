#pragma once

#include "../../grid.hpp"
#include "../../models/player.hpp"

class TicTacToeGrid : public Grid<PlayerId>
{
public:
    TicTacToeGrid() : Grid(xSize, ySize, NO_PLAYER){};

private:
    static constexpr unsigned int xSize = 3;
    static constexpr unsigned int ySize = 3;
};
