//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERSEVALUATOR_H
#define LIVL_CHECKERSEVALUATOR_H


#include <memory>
#include "models/interfaces/GameEvaluator.h"
#include <optional>
#include <stdexcept>

class CheckersEvaluator  : public GameEvaluator {
public:
    bool hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) override;

    [[nodiscard]] PlayerId getWinner(const Grid<Token> &grid) const override;

    static std::optional<Position> getCapturableEnemyTokenPosition(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to);

    static unsigned int getDialognalDistance(const Position &from, const Position &to);

    static std::vector<Position> getValidTokenMoves(const Grid<Token> &grid, Position position);

};


#endif //LIVL_CHECKERSEVALUATOR_H
