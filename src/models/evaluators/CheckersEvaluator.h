//
// Created by Julien on 30/01/2023.
//

#ifndef LIVL_CHECKERSEVALUATOR_H
#define LIVL_CHECKERSEVALUATOR_H


#include <memory>
#include "models/interfaces/GameEvaluator.h"


class CheckersEvaluator  : public GameEvaluator {
public:
    bool hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) override;

    [[nodiscard]] PlayerId getWinner(const Grid<Token> &grid) const override;

    static bool isMoveValid(const Position &from, const Position &to);

    static std::optional<Position> getCapturableEnemyTokenPosition(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to);

};


#endif //LIVL_CHECKERSEVALUATOR_H
