#pragma once

#include "../../interfaces/grid.hpp"
#include "../../models/player.hpp"
#include "checkersToken.hpp"

class CheckersGrid : public Grid<CheckersToken>
{
public:
    CheckersGrid() : Grid(xSize, ySize, )
    {
        // place default token on the board for a checkers game for element 1 and 2 in horizontal direction
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < xSize; j++) {
                if ((i + j) % 2 == 1) {
                    this->place({j, i}, 1);
                }
            }
        }
        for (int i = ySize - 1; i > ySize - 4; i--) {
            for (int j = 0; j < xSize; j++) {
                if ((i + j) % 2 == 1) {
                    this->place({j, i}, 2);
                }
            }
        }
    };
    explicit CheckersGrid(const Grid<CheckersToken> &other) : Grid<CheckersToken>(other) {}

    static constexpr int xSize = 8;
    static constexpr int ySize = 8;
};


