#pragma once

#include "grid.hpp"
#include "player.hpp"
#include <vector>
#include <string>

class Game
{
public:

    /**
     * @brief Construct a new Game object
     * 
     * @param name 
     * @param xSize 
     * @param ySize 
     * @param pointsToWin 
     * @param players 
     */
    Game(
        std::string name, 
        unsigned int xSize, 
        unsigned int ySize, 
        unsigned int pointsToWin, 
        std::vector<Player> players
    );

    /**
     * @brief Destroy the Game object
     * 
     */
    ~Game();

    /**
     * @brief Start the game
     * 
     */
    void play();

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

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    inline std::string getName() const { return this->name; };

private:

    std::string name;
    unsigned int round = 0;
    unsigned int playerCount = 0;
    std::vector<Player> players;
    Grid grid;
    unsigned int consecutiveSymbolsToWin;
    bool isFinished = false;

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
    Cell askForCell(const char playerChar) const;

    /**
     * @brief Play as computer : place his symbol on a free grid cell
     * 
     * @param playerId 
     */
    void playAsComputer(int playerId);
    
};