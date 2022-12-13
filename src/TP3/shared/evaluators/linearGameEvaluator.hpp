#pragma once

#include "../../grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class LinearGameEvaluator : public GameEvaluator
{
public:
    LinearGameEvaluator(const unsigned int consecutiveIdsToWin) : GameEvaluator(consecutiveIdsToWin) {}

    /**
     * @brief Return true if the given id have won the game
     *
     * @param id
     * @return true
     * @return false
     */
    bool hasPlayerWon(const PlayerId id, const Grid<PlayerId> &grid) const override;

private:
    void checkRows(const PlayerId id, const Grid<PlayerId> &grid, unsigned int &maxConsecutive) const;

    void checkColumns(const PlayerId id, const Grid<PlayerId> &grid, unsigned int &maxConsecutive) const;

    void checkDiagonals(const PlayerId id, const Grid<PlayerId> &grid, unsigned int &maxConsecutive) const;

    void checkMaxConsecutive(const PlayerId id, const Grid<PlayerId> &grid, unsigned int startRow, unsigned int startCol, unsigned int rowStep, unsigned int colStep, unsigned int &maxConsecutive) const;
};