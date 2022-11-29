#pragma once

#include "../../interfaces/cellRequester.hpp"
#include "../../models/cell.hpp"
#include "../../shared/functions.hpp"
#include <iostream>

class Power4CellRequester : public CellRequester
{
public:
    Power4CellRequester(const Grid &grid) : CellRequester(grid){};

    Cell askForCell(const char playerChar) override;
};