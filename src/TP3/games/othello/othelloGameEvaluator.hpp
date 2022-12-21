#pragma once

#include "../../interfaces/grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class OthelloGameEvaluator : public GameEvaluator
{
public:
    OthelloGameEvaluator() : GameEvaluator() {}

    bool hasGameEnded(const PlayerId nextPlayerId) override;

    PlayerId getWinner() const override;

    static bool canPlaceToken(const Position &pos, const PlayerId playerId, const Grid<PlayerId> &grid);

    static std::vector<Position> getFlippablePieces(const Position &pos, PlayerId playerId, const Position &direction, const Grid<PlayerId> &grid);

    static std::vector<Position> getValidPositions(PlayerId playerId, const Grid<PlayerId> &grid);

    static Position getBestPosition(const std::vector<Position> &validPositions, PlayerId playerId, const Grid<PlayerId> &grid);
};