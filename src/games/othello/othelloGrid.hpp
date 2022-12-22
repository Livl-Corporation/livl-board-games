#pragma once

#include "../../interfaces/grid.hpp"
#include "../../models/player.hpp"

class OthelloGrid : public Grid<PlayerId>
{
public:
    OthelloGrid() : Grid(size, size, NO_PLAYER)
    {
        this->place({3, 3}, 1);
        this->place({4, 4}, 1);
        this->place({3, 4}, 2);
        this->place({4, 3}, 2);
    };

    explicit OthelloGrid(const Grid<PlayerId> &other) : Grid<PlayerId>(other) {}

private:
    static constexpr unsigned int size = 8;
};
