#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../models/player.hpp"
#include "othelloGameEvaluator.hpp"

class OthelloPositionRequester : public PositionRequester
{
public:
    Position askForPosition(const PlayerId playerId) const override;
};