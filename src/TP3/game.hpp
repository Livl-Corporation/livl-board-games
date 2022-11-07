#pragma once

#include "grid.hpp"
#include "player.hpp"
#include <vector>

class Game
{
public:

    /**
     * @brief Start the game
     * 
     */
    void play();

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
    bool hasWon(int id) const;

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

private:

    unsigned int round = 0;
    unsigned int playerCount = 0;
    std::vector<Player> players;
    Grid grid;
    unsigned int consecutiveSymbolsToWin;

    /**
     * @brief End a game with a winner
     * 
     * @param playerId 
     */
    void win(int playerId);

    /**
     * @brief End a game on a tie
     * 
     */
    void tie();

    /**
     * @brief Ask the player to enter a cell
     *
     * @return Cell
     */
    Cell askForCell();
    
};