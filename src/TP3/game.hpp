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
        std::vector<Player> players);

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

    /**
     * @brief Get the Grid object
     *
     * @return Grid
     */
    inline Grid &getGrid() { return this->grid; };

    /**
     * @brief Get the Players object
     *
     * @return std::vector<Player>
     */
    std::vector<Player> getPlayers() const;

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
    virtual Cell askForCell(const char playerChar);

    /**
     * @brief Play as computer : place his symbol on a free grid cell
     *
     * @param playerId
     */
    virtual Cell playAsComputer(int playerId);
};