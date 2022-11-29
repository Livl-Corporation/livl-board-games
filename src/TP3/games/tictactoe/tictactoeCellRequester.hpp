#pragma once

#include "../../interfaces/cellRequester.hpp"
#include "../../models/cell.hpp"
#include <iostream>

class TicTacToeCellRequester : public CellRequester
{
public:
    TicTacToeCellRequester(const Grid &grid) : CellRequester(grid){};

    Cell askForCell(const char playerChar) override;
};