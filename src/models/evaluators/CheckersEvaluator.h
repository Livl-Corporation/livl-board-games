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

    static bool isMoveValid(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to);

    static bool captureEnemyToken(std::shared_ptr<Grid<Token>> &grid, const Position &from, const Position &to);

    static bool isCaptureMove(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to);

    static bool forceEnemyToCaptureEnemy(std::shared_ptr<Grid<Token>> &grid, const PlayerId &playerId, const Position &from, Position &capturableEnemyPos);

};


#endif //LIVL_CHECKERSEVALUATOR_H
