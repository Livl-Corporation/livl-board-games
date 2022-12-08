#pragma once

#include "../../interfaces/cellRequester.hpp"
#include "../../models/cell.hpp"
#include <iostream>

class TicTacToeCellRequester : public CellRequester
{
public:
    Cell askForCell(const char playerChar, const Grid &grid) const override;
};