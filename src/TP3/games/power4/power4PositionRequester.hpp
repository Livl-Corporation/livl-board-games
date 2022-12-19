#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../shared/consoleHandler.hpp"
#include "power4Grid.hpp"

class Power4PositionRequester : public PositionRequester
{
public:
    Position askForPosition(const char playerChar, const Grid<PlayerId> &grid) const override;
};