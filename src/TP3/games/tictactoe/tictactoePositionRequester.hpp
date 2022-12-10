#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include <iostream>

class TicTacToePositionRequester : public PositionRequester
{
public:
    Position askForPosition(const char playerChar, const Grid &grid) const override;
};