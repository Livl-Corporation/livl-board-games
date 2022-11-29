#pragma once

#include "grid.hpp"

#include "models/player.hpp"
#include "models/cell.hpp"

#include "interfaces/gameEvaluator.hpp"
#include "interfaces/cellRequester.hpp"

#include "shared/functions.hpp"
#include "shared/exceptions/out-of-bounds-exception.hpp"

#include <iostream>
#include <cstdio>
#include <sstream>
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
     * @param gameEvaluator
     * @param cellRequester
     * @param players
     */
    Game(
        const std::string name,
        const unsigned int xSize,
        const unsigned int ySize,
        // GameEvaluator &gameEvaluator,
        // CellRequester &cellRequester,
        const std::vector<Player> players);

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

protected:
    GameEvaluator *gameEvaluator;
    CellRequester *cellRequester;

private:
    std::string name;
    unsigned int round = 0;
    unsigned int playerCount = 0;
    std::vector<Player> players;
    Grid grid;
    bool isFinished = false;

    /**
     * @brief Start playing the next game round
     *
     */
    void nextRound();

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
     * @brief Play as computer : place his symbol on a free grid cell
     *
     * @param playerId
     */
    virtual Cell playAsComputer(const unsigned int playerId);
};