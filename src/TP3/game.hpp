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
    void nextRound();

    /**
     * @brief Returns true if provided player has won
     *
     * @param symbol
     * @return true
     * @return false
     */
    bool hasWon(Symbol symbol) const;

    /**
     * @brief Get the Round object
     *
     * @return unsigned int
     */
    inline unsigned int getRound() const { return this->round; };

    /**
     * @brief Get the Player Count object
     *
     * @return unsigned int
     */
    inline unsigned int getPlayerCount() const { return this->playerCount; };

protected:
    unsigned int round = 0;
    unsigned int playerCount = 0;
    std::vector<Symbol> players;
    Grid grid;
    unsigned int consecutiveSymbolsToWin;

    /**
     * @brief Ask the player to enter a cell
     *
     * @return Cell
     */
    Cell askForCell() const;
};