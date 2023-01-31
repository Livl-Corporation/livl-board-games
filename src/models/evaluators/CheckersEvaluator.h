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

    static bool isMoveValid(std::shared_ptr<Grid<Token>> &grid, const PlayerId &playerId, const Position &from, const Position &to) const;

    static bool captureEnemyToken(std::shared_ptr<Grid<Token>> &grid, const Position &from, const Position &to) const;

    static bool isCaptureMove(std::shared_ptr<Grid<Token>> &grid, const PlayerId &playerId, const Position &from, const Position &to) const;

    static bool forceEnemyToCaptureEnemy(std::shared_ptr<Grid<Token>> &grid, const PlayerId &playerId, const Position &from, Position &capturableEnemyPos) const;

};


#endif //LIVL_CHECKERSEVALUATOR_H
