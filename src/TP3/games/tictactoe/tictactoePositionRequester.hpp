#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../shared/consoleHandler.hpp"
#include "../../models/player.hpp"

class TicTacToePositionRequester : public PositionRequester
{
public:
    Position askForPosition(const PlayerId playerId, const Grid<PlayerId> &grid) const override;
};