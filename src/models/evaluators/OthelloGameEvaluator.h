//
// Created by Franck GUTMANN on 30/01/2023.
//

#ifndef LIVL_OTHELLOGAMEEVALUATOR_H
#define LIVL_OTHELLOGAMEEVALUATOR_H


#include "models/PlayerId.h"
#include "models/Position.h"
#include "models/Grid.h"
#include "models/interfaces/GameEvaluator.h"

class OthelloGameEvaluator : public GameEvaluator {
public:
    bool hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) override;

    [[nodiscard]] PlayerId getWinner(const Grid<Token> &grid) const override;

    static bool canPlaceToken(const Position &pos, PlayerId playerId, const Grid<Token> &grid);

    static std::vector<Position> getFlippablePieces(const Position &pos, const PlayerId &playerId, const Position &direction, const Grid<Token> &grid);

    static std::vector<Position> getValidPositions(const PlayerId &playerId, const Grid<Token> &grid);

    static Position getBestPosition(const std::vector<Position> &validPositions, const PlayerId &playerId, const Grid<Token> &grid);
};


#endif //LIVL_OTHELLOGAMEEVALUATOR_H
