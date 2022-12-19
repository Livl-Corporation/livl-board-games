#pragma once

#include "../../interfaces/positionRequester.hpp"

class OthelloPositionRequester : public PositionRequester{
public:
    Position askForPosition(const char playerChar, const Grid<PlayerId> &grid) const override;
private:
    bool canPlaceToken(const Position &pos, char playerChar, char opponentChar, const Grid<PlayerId> &grid) const;
};