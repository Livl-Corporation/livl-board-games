#pragma once

#include "grid.hpp"
#include "symbol.hpp"
#include <vector>

class Game
{
public:
    /**
     * @brief Start playing the next game round
     *
     */
    void nextRound()
    {
    }

    /**
     * @brief Returns true if provided player has won
     *
     * @param symbol
     * @return true
     * @return false
     */
    bool hasWon(Symbol symbol) const;

private:
    unsigned int round = 0;
    Symbol currentRound;
    std::vector<Symbol> players;
    Grid grid;
    unsigned int symbolsToWin;
};