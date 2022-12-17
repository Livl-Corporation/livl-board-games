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

    virtual bool hasPlayerWon(const PlayerId id, const Grid<PlayerId> &grid) const = 0;

protected:
    unsigned int consecutiveIdsToWin;
};