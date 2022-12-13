#pragma once

#include "../grid.hpp"
#include <memory>

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
    virtual bool hasPlayerWon(const PlayerId id, const Grid<PlayerId> &grid) const = 0;

protected:
    unsigned int consecutiveIdsToWin;
};