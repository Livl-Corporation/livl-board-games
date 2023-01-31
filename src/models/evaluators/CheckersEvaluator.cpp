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

    if (getDialognalDistance(from, to) != 2) {
        return std::nullopt;
    }

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

unsigned int CheckersEvaluator::getDialognalDistance(const Position &from, const Position &to) {

    unsigned int rowDistance = std::abs(to.row - from.row);
    unsigned int colDistance = std::abs(to.col - from.col);

    if(rowDistance != colDistance) {
        throw std::invalid_argument("The positions are not diagonal");
    }

    return rowDistance;
}

bool CheckersEvaluator::canTokenMove(const Grid<Token> &grid, Position position) {
    // check if the token can move forward
    std::vector<Position> directions = {{1,1}, {1,-1}};

    // invert direction if the token is owned by player 2
    int multiplier = (grid.getElementAt(position).getPlayerId() == 2) ? -1 : 1;

    // TODO : If king, check if the token can move backwards


    // check if position is free
    for(auto direction : directions) {
        Position nextPosition = {position.row + direction.row*multiplier, position.col + direction.col*multiplier};

        if(grid.isPositionInBounds(nextPosition)) {

            // Check if adjacent position is free
            if(grid.getElementAt(nextPosition).getPlayerId() == NO_PLAYER) {
                return true;
            } else if (grid.getElementAt(nextPosition).getPlayerId() != grid.getElementAt(position).getPlayerId()) {
                // Check if the token can capture an enemy token
                Position nextNextPosition = {nextPosition.row + direction.row*multiplier, nextPosition.col + direction.col*multiplier};

                if(grid.isPositionInBounds(nextNextPosition) && grid.getElementAt(nextNextPosition).getPlayerId() == NO_PLAYER) {
                    return true;
                }
            }


        }
    }


}


