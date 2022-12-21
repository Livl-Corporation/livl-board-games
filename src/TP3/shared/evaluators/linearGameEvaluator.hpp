#pragma once

#include "../../grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class LinearGameEvaluator : public GameEvaluator
{
public:
    LinearGameEvaluator(const unsigned int consecutiveIdsToWin) : GameEvaluator()
    {
        this->consecutiveIdsToWin = consecutiveIdsToWin;
    }

    bool hasGameEnded() override;

    PlayerId getWinner() const override;

private:
    bool hasPlayerWon(const PlayerId id) const;

    void checkRows(const PlayerId id, unsigned int &maxConsecutive) const;

    void checkColumns(const PlayerId id, unsigned int &maxConsecutive) const;

    void checkDiagonals(const PlayerId id, unsigned int &maxConsecutive) const;

    void checkMaxConsecutive(const PlayerId id, unsigned int startRow, unsigned int startCol, unsigned int rowStep, unsigned int colStep, unsigned int &maxConsecutive) const;

    unsigned int consecutiveIdsToWin;

    PlayerId winner = NO_PLAYER;
};