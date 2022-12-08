#pragma once

#include "../../interfaces/cellRequester.hpp"
#include "../../models/cell.hpp"
#include "../../shared/functions.hpp"
#include <iostream>

class Power4CellRequester : public CellRequester
{
public:
    Cell askForCell(const char playerChar, const Grid &grid) override;
};