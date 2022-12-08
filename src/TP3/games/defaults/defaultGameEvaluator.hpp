#pragma once

#include "../../grid.hpp"
#include "../../interfaces/gameEvaluator.hpp"

class DefaultGameEvaluator : public GameEvaluator
{
public:
    DefaultGameEvaluator(const unsigned int consecutiveIdsToWin) : GameEvaluator(consecutiveIdsToWin) {}

    /**
     * @brief Return true if the given id have won the game
     *
     * @param id
     * @return true
     * @return false
     */
    bool hasPlayerWon(const unsigned int id, const Grid &grid) override;

private:
    void checkRows(const unsigned int id, const Grid &grid, unsigned int &maxConsecutive);

    void checkColumns(const unsigned int id, const Grid &grid, unsigned int &maxConsecutive);

    void checkDiagonals(const unsigned int id, const Grid &grid, unsigned int &maxConsecutive);

    void checkMaxConsecutive(const unsigned int id, const Grid &grid, unsigned int startRow, unsigned int startCol, unsigned int rowStep, unsigned int colStep, unsigned int &maxConsecutive);
};