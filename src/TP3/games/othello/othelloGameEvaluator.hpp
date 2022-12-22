#pragma once

#include "../../interfaces/grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class OthelloGameEvaluator : public GameEvaluator
{
public:
    OthelloGameEvaluator() : GameEvaluator() {}

    bool hasGameEnded(const PlayerId &nextPlayerId) override;

    [[nodiscard]] PlayerId getWinner() const override;

    static bool canPlaceToken(const Position &pos, PlayerId playerId, const Grid<PlayerId> &grid);

    static std::vector<Position> getFlippablePieces(const Position &pos, const PlayerId &playerId, const Position &direction, const Grid<PlayerId> &grid);

    static std::vector<Position> getValidPositions(const PlayerId &playerId, const Grid<PlayerId> &grid);

    static Position getBestPosition(const std::vector<Position> &validPositions, const PlayerId &playerId, const Grid<PlayerId> &grid);
};