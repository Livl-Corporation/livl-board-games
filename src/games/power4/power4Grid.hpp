#pragma once

#include "../../interfaces/grid.hpp"
#include "../../models/player.hpp"

class Power4Grid : public Grid<PlayerId>
{
public:
    Power4Grid() : Grid(xSize, ySize, NO_PLAYER){};

    explicit Power4Grid(const Grid<PlayerId> &other) : Grid<PlayerId>(other) {}

    [[nodiscard]] int firstRowAvailableInCol(int col) const;

private:
    static constexpr unsigned int xSize = 7; // declared as constexpr so that they can be used as compile-time constants.
    static constexpr unsigned int ySize = 4;
};
