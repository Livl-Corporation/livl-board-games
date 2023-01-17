#pragma once

#include "power4Grid.hpp"
#include "../../interfaces/positionRequester.hpp"
#include "../../cli/consoleHandler.hpp"

class Power4PositionRequester : public PositionRequester
{
public:
    [[nodiscard]] Position askForPosition(const PlayerId &playerId) const override;
};