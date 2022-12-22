#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../shared/consoleHandler.hpp"
#include "power4Grid.hpp"
#include "../../models/player.hpp"

class Power4PositionRequester : public PositionRequester
{
public:
    [[nodiscard]] Position askForPosition(const PlayerId &playerId) const override;
};