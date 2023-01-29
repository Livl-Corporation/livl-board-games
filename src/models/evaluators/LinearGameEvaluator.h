//
// Created by Franck GUTMANN on 29/01/2023.
//

#ifndef LIVL_LINEARGAMEEVALUATOR_H
#define LIVL_LINEARGAMEEVALUATOR_H


#include "models/interfaces/GameEvaluator.h"

class LinearGameEvaluator : public GameEvaluator {


public:

    explicit LinearGameEvaluator(const unsigned int consecutiveIdsToWin) : GameEvaluator()
    {
        this->consecutiveIdsToWin = consecutiveIdsToWin;
    }

    bool hasGameEnded(const Grid<Token> &grid, const PlayerId &nextPlayerId) override;

    PlayerId getWinner(const Grid<Token> &grid) const override;

private:
    [[nodiscard]] bool hasPlayerWon(const Grid<Token> &grid, const PlayerId &id) const;

    void checkRows(const Grid<Token> &grid, const PlayerId &id, unsigned int &maxConsecutive) const;

    void checkColumns(const Grid<Token> &grid, const PlayerId &id, unsigned int &maxConsecutive) const;

    void checkDiagonals(const Grid<Token> &grid, const PlayerId &id, unsigned int &maxConsecutive) const;

    void checkMaxConsecutive(const Grid<Token> &grid, const PlayerId &id, int startRow, int startCol, int rowStep, int colStep, unsigned int &maxConsecutive) const;

    unsigned int consecutiveIdsToWin;

    PlayerId winner = NO_PLAYER;
};


#endif //LIVL_LINEARGAMEEVALUATOR_H
