#pragma once

#include "../../interfaces/positionRequester.hpp"
#include "../../models/position.hpp"
#include "../../models/player.hpp"

class OthelloPositionRequester : public PositionRequester
{
public:
    Position askForPosition(const PlayerId playerId, const Grid<PlayerId> &grid) const override;

private:
    bool canPlaceToken(const Position &pos, const PlayerId playerId, const Grid<PlayerId> &grid) const;
};