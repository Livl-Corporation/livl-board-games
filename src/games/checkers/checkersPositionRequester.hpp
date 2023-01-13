#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../models/player.hpp"

class CheckersPositionRequester : public PositionRequester
{
public:
    [[nodiscard]] Position askForPosition(const PlayerId &playerId) const override;
    static bool isMoveValid(const PlayerId &playerId, const Position &from, const Position &to);
};