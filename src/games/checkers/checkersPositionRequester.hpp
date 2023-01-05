#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../models/player.hpp"

class CheckersPositionRequester : public PositionRequester
{
public:
    Position askForPosition(const PlayerId &playerId) const;
};