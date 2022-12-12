#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../shared/functions.hpp"
#include "../../shared/consoleHandler.hpp"

class Power4PositionRequester : public PositionRequester
{
public:
    Position askForPosition(const char playerChar, const Grid &grid) const override;
};