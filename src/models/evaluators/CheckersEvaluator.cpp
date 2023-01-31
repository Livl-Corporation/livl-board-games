//
// Created by Julien on 30/01/2023.
//

#include <optional>
#include "CheckersEvaluator.h"

bool CheckersEvaluator::hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) {
    return false;
}

PlayerId CheckersEvaluator::getWinner(const Grid<Token> &grid) const {
    return 0;
}

//bool CheckersEvaluator::forceEnemyToCaptureEnemy(std::shared_ptr<Grid<Token>> &grid, const PlayerId &playerId, const Position &from, Position &capturableEnemyPos) {
//    PlayerId enemyPlayerId = (playerId == 1) ? 2 : 1;
//
//    Position diag1{}, diag2{};
//    bool positionHasEnemyTokenDiag1;
//    bool positionHasEnemyTokenDiag2;
//
//    // check only two diagonals because a player can only move forward and not backwards
//    if(enemyPlayerId == 1) {
//        diag1 = {from.row + 2, from.col - 2};
//        diag2 = {from.row - 2, from.col - 2};
//        positionHasEnemyTokenDiag1 = grid->getElementAt({diag1.row-1,diag1.col+1}).getPlayerId() == enemyPlayerId;
//        positionHasEnemyTokenDiag2 = grid->getElementAt({diag2.row+1,diag2.col+1}).getPlayerId() == enemyPlayerId;
//    } else {
//        diag1 = {from.row + 2, from.col + 2};
//        diag2 = {from.row - 2, from.col + 2};
//        positionHasEnemyTokenDiag1 = grid->getElementAt({diag1.row-1,diag1.col-1}).getPlayerId() == enemyPlayerId;
//        positionHasEnemyTokenDiag2 = grid->getElementAt({diag1.row+1,diag1.col-1}).getPlayerId() == enemyPlayerId;
//    }
//
//    if(grid->isPositionInBounds(diag1) && grid->getElementAt(diag1).getPlayerId() == NO_PLAYER && positionHasEnemyTokenDiag1) {
//        capturableEnemyPos = diag1;
//        return true;
//    }
//
//    if(grid->isPositionInBounds(diag2) && grid->getElementAt(diag2).getPlayerId() == NO_PLAYER && positionHasEnemyTokenDiag2) {
//        capturableEnemyPos = diag2;
//        return true;
//    }
//
//    return false;
//}

std::optional<Position> CheckersEvaluator::getCapturableEnemyTokenPosition(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to) {

    // check if the position in between the from and to positions is occupied by the enemy player
    int enemyPlayerId = (playerId == 1) ? 2 : 1;
    int enemyTokenRow = (from.row + to.row) / 2;
    int enemyTokenCol = (from.col + to.col) / 2;

    if (grid.getElementAt({enemyTokenRow, enemyTokenCol}).getPlayerId() == enemyPlayerId) {
        Position enemyTokenPos = {enemyTokenRow, enemyTokenCol};
        return enemyTokenPos;
    }

    return std::nullopt;
}

bool CheckersEvaluator::isMoveValid(const Position &from, const Position &to) {
    // check if the move is a capture move (difference in x and y positions is 2 (2 = the move is 2 positions diagonally))
    return std::abs(to.row - from.row) == 2 && std::abs(to.row - from.col) == 2;
}
