//
// Created by Julien on 30/01/2023.
//

#include "CheckersEvaluator.h"

bool CheckersEvaluator::hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) {
    return false;
}

PlayerId CheckersEvaluator::getWinner(const Grid<Token> &grid) const {
    return 0;
}

bool CheckersEvaluator::forceEnemyToCaptureEnemy(std::shared_ptr<Grid<Token>> &grid, const PlayerId &playerId, const Position &from, Position &capturableEnemyPos) {
    PlayerId enemyPlayerId = (playerId == 1) ? 2 : 1;

    Position diag1, diag2;
    bool positionHasEnemyTokenDiag1;
    bool positionHasEnemyTokenDiag2;

    // check only two diagonals because a player can only move forward and not backwards
    if(enemyPlayerId == 1) {
        diag1 = Position(from.row + 2, from.col - 2);
        diag2 = Position(from.row - 2, from.col - 2);
        positionHasEnemyTokenDiag1 = grid->getElementAt(Position(diag1.row-1,diag1.col+1)).getPlayerId() == enemyPlayerId;
        positionHasEnemyTokenDiag2 = grid->getElementAt(Position(diag2.row+1,diag2.col+1)).getPlayerId() == enemyPlayerId;
    } else {
        diag1 = Position(from.row + 2, from.col + 2);
        diag2 = Position(from.row - 2, from.col + 2);
        positionHasEnemyTokenDiag1 = grid->getElementAt(Position(diag1.row-1,diag1.col-1)).getPlayerId() == enemyPlayerId;
        positionHasEnemyTokenDiag2 = grid->getElementAt(Position(diag1.row+1,diag1.col-1)).getPlayerId() == enemyPlayerId;
    }

    if(grid->isPositionInBounds(diag1) && grid->getElementAt(diag1).getPlayerId() == NO_PLAYER && positionHasEnemyTokenDiag1) {
        capturableEnemyPos = diag1;
        return true;
    }

    if(grid->isPositionInBounds(diag2) && grid->getElementAt(diag2).getPlayerId() == NO_PLAYER && positionHasEnemyTokenDiag2) {
        capturableEnemyPos = diag2;
        return true;
    }

    return false;
}

bool CheckersEvaluator::captureEnemyToken(std::shared_ptr<Grid<Token>> &grid, const Position &from, const Position &to) {
    if(!grid->isPositionInBounds(from) || !grid->isPositionInBounds(to))
        return false;

    if(grid->getElementAt(from).getPlayerId() == NO_PLAYER || grid->getElementAt(to).getPlayerId() != NO_PLAYER)
        return false;

    int xDiff = abs(to.row - from.row);
    int yDiff = abs(to.col - from.col);

    if(xDiff != 2 || yDiff != 2)
        return false;

    Position enemyPos = {(to.row+from.row)/2, (to.col+from.col)/2};

    if(grid->getElementAt(enemyPos) == grid->getElementAt(from))
        return false;

    grid->replaceAt(enemyPos, Token{});
    return true;
}

bool CheckersEvaluator::isCaptureMove(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to) {
    // check if the move is a capture move (difference in x and y positions is 2 (2 = the move is 2 positions diagonally))
    if (std::abs(to.row - from.row) != 2 || std::abs(to.row - from.col) != 2) {
        return false;
    }

    // check if the position in between the from and to positions is occupied by the enemy player
    int enemyPlayerId = (playerId == 1) ? 2 : 1;
    int enemyTokenX = (from.row + to.row) / 2;
    int enemyTokenY = (from.col + to.col) / 2;

    if (grid.getElementAt({enemyTokenX, enemyTokenY}).getPlayerId() == enemyPlayerId) {
        return true;
    }

    return false;
}

bool CheckersEvaluator::isMoveValid(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to) {
    if (isCaptureMove(grid, playerId, from, to)) {
        //this->captureEnemyToken(grid, from, to);
        return true;
    }

    // check if the move is diagonal
    if (std::abs(to.row - from.row) != std::abs(to.col - from.col)) {
        return false;
    }

    // check if the move is just one step
    if (std::abs(to.row - from.row) != 1) {
        return false;
    }

    // check if player is moving backward
    if (playerId == 1 && to.row < from.col) {
        return false;
    }
    if (playerId == 2 && to.row > from.col) {
        return false;
    }

    return true;
}
