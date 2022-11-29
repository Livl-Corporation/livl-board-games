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
};