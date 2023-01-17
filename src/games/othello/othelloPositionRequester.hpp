#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../models/player.hpp"
#include "../../cli/consoleHandler.hpp"
#include "othelloGameEvaluator.hpp"

class OthelloPositionRequester : public PositionRequester
{
public:
    [[nodiscard]] Position askForPosition(const PlayerId &playerId) const override;
};