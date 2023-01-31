//
// Created by Julien on 30/01/2023.
//

#include "CheckersEvaluator.h"
#include "models/games/checkers/tokens/CheckersTokenType.h"

bool CheckersEvaluator::hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) {
    return allEnemyTokensAreCaptured(grid, nextPlayerId) || noValidMoves(grid, nextPlayerId);
}

PlayerId CheckersEvaluator::getWinner(const Grid<Token> &grid) const {
    return winner.value();
}

bool CheckersEvaluator::allEnemyTokensAreCaptured(const Grid<Token> &grid, const PlayerId &nextPlayerId)  {
    PlayerId actualPlayerId = (nextPlayerId == 1) ? 2 : 1;
    for (int row = 0; row < grid.getRowCount(); row++) {
        for (int col = 0; col < grid.getColCount(); col++) {
            std::shared_ptr<Token> token = grid.getElementAt({row, col});
            if (token->getPlayerId() == actualPlayerId) {
                return false;
            }
        }
    }

    winner = nextPlayerId;
    return true;
}

bool CheckersEvaluator::noValidMoves(const Grid<Token> &grid, const PlayerId &nextPlayerId) {
    // check if no valid moves are available for the nextPlayerId
    for (int row = 0; row < grid.getRowCount(); row++) {
        for (int col = 0; col < grid.getColCount(); col++) {
            std::shared_ptr<Token> token = grid.getElementAt({row, col});
            if (token->getPlayerId() == nextPlayerId) {
                std::vector<Position> validMoves = getValidTokenMoves(grid, {row, col});
                if (!validMoves.empty()) {
                    return false;
                }
            }
        }
    }

    winner = (nextPlayerId == 1) ? 2 : 1;
    return true;
}

std::optional<Position> CheckersEvaluator::getCapturableEnemyTokenPosition(const Grid<Token> &grid, const PlayerId &playerId, const Position &from, const Position &to) {

    if (getDialognalDistance(from, to) != 2) {
        return std::nullopt;
    }

    // check if the position in between the from and to positions is occupied by the enemy player
    int enemyTokenRow = (from.row + to.row) / 2;
    int enemyTokenCol = (from.col + to.col) / 2;

    PlayerId middleTokenPlayerId = grid.getElementAt({enemyTokenRow, enemyTokenCol})->getPlayerId();
    if (middleTokenPlayerId != NO_PLAYER && middleTokenPlayerId != playerId) {
        Position enemyTokenPos = {enemyTokenRow, enemyTokenCol};
        return enemyTokenPos;
    }

    return std::nullopt;
}

std::vector<Position> CheckersEvaluator::getValidTokenMoves(const Grid<Token> &grid, Position position) {

    std::vector<Position> validMoves;

    Token token = *grid.getElementAt(position);

    // check if the token can move forward
    std::vector<Position> directions = {{1,1}, {1,-1}};

    // invert direction if the token is owned by player 2
    int multiplier = (token.getType() != CheckersTokenType::KING && token.getPlayerId() == 2) ? -1 : 1;

    // Add backwards direction if token is king
    if(token.getType() == CheckersTokenType::KING) {
        directions.emplace_back(-1,1);
        directions.emplace_back(-1,-1);
    }

    for(auto direction : directions) {
        Position nextPosition = {position.row + direction.row*multiplier, position.col + direction.col*multiplier};

        if(grid.isPositionInBounds(nextPosition)) {

            if (grid.getElementAt(nextPosition)->getPlayerId() != grid.getElementAt(position)->getPlayerId()) {
                // Check if the token can capture an enemy token
                Position nextNextPosition = {nextPosition.row + direction.row*multiplier, nextPosition.col + direction.col*multiplier};

                if(grid.isPositionInBounds(nextNextPosition) && grid.getElementAt(nextNextPosition)->getPlayerId() == NO_PLAYER) {
                    validMoves.push_back(nextNextPosition);
                }
            } // Check if adjacent position is free
            else (grid.getElementAt(nextPosition)->getPlayerId() == NO_PLAYER); {
                validMoves.push_back(nextPosition);
            }

        }
    }

    return validMoves;

}

unsigned int CheckersEvaluator::getDialognalDistance(const Position &from, const Position &to) {
    unsigned int rowDistance = abs(from.row - to.row);
    unsigned int colDistance = abs(from.col - to.col);

    if(rowDistance != colDistance) {
        throw std::invalid_argument("The two positions are not diagonal");
    }

    return rowDistance;
}