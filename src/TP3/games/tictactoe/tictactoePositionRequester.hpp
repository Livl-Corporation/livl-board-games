#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../shared/consoleHandler.hpp"

class TicTacToePositionRequester : public PositionRequester
{
public:
    Position askForPosition(const char playerChar, const Grid &grid) const override;
};