#pragma once

#include "../grid.hpp"

class GameEvaluator
{
public:
    GameEvaluator(const unsigned int consecutiveIdsToWin)
    {
        this->consecutiveIdsToWin = consecutiveIdsToWin;
    };

    /**
     * @brief Return true if the given id have won the game
     *
     * @param id
     * @return true
     * @return false
     */
    virtual bool hasPlayerWon(const unsigned int id, const Grid &grid) = 0;

protected:
    unsigned int consecutiveIdsToWin;
};