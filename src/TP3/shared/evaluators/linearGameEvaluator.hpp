#pragma once

#include "../../interfaces/grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class LinearGameEvaluator : public GameEvaluator
{
public:
    explicit LinearGameEvaluator(const unsigned int consecutiveIdsToWin) : GameEvaluator()
    {
        this->consecutiveIdsToWin = consecutiveIdsToWin;
    }

    bool hasGameEnded(const PlayerId &nextPlayerId) override;

    [[nodiscard]] PlayerId getWinner() const override;

private:
    [[nodiscard]] bool hasPlayerWon(const PlayerId &id) const;

    void checkRows(const PlayerId &id, unsigned int &maxConsecutive) const;

    void checkColumns(const PlayerId &id, unsigned int &maxConsecutive) const;

    void checkDiagonals(const PlayerId &id, unsigned int &maxConsecutive) const;

    void checkMaxConsecutive(const PlayerId &id, int startRow, int startCol, int rowStep, int colStep, unsigned int &maxConsecutive) const;

    unsigned int consecutiveIdsToWin;

    PlayerId winner = NO_PLAYER;
};