#pragma once

#include "../../interfaces/positionRequester.hpp"

class OthelloPositionRequester : public PositionRequester{
    Position askForPosition(const char playerChar, const Grid<PlayerId> &grid) const override;
};