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
#include <memory>

class Game
{
public:
    /**
     * @brief Construct a new Game object
     *
     * @param name
     * @param xSize
     * @param ySize
     * @param players
     * @param cellRequester A unique pointer to a cell requester
     * @param gameEvaluator A unique pointer to a game evaluator
     */
    Game(
        const std::string name,
        const unsigned int xSize,
        const unsigned int ySize,
        const std::vector<Player> players,
        std::unique_ptr<CellRequester> cellRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator);

    ~Game();

    /**
     * @brief Start the game
     */
    void play();

    inline unsigned int getRound() const { return this->round; };

    inline unsigned int getPlayerCount() const { return this->playerCount; };

    inline std::string getName() const { return this->name; };

    inline Grid &getGrid() { return this->grid; };

    std::vector<Player> getPlayers() const;

protected:
    std::unique_ptr<CellRequester> cellRequester;
    std::unique_ptr<GameEvaluator> gameEvaluator;

    /**
     * @brief Play as computer : place his symbol on a free grid cell
     *
     * @param playerId  The player id
     */
    virtual Cell playAsComputer(const unsigned int playerId);

private:
    /**
     * @brief The game name (ex: Tic Tac Toe)
     */
    std::string name;

    /**
     * @brief The round number (starts at 0)
     */
    unsigned int round = 0;

    /**
     * @brief The number of players
     */
    unsigned int playerCount = 0;

    /**
     * @brief The players list in the game
     */
    std::vector<Player> players;

    /**
     * @brief The grid (ex: 3x3 for Tic Tac Toe)
     */
    Grid grid;

    /**
     * @brief If the game is finished
     */
    bool isFinished = false;

    /**
     * @brief Start playing the next game round
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
};