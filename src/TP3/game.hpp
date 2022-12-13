#pragma once

#include "grid.hpp"
#include "games/power4/power4Grid.hpp"
#include "games/tictactoe/tictactoeGrid.hpp"

#include "models/player.hpp"
#include "models/position.hpp"

#include "interfaces/gameEvaluator.hpp"
#include "interfaces/positionRequester.hpp"

#include "shared/shared.hpp"
#include "shared/consoleHandler.hpp"
#include "shared/exceptions/out-of-bounds-exception.hpp"

#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

class Game
{
public:
    /**
     * @brief Start the game
     */
    void play();

    inline unsigned int getRound() const { return this->round; };

    inline unsigned int getPlayerCount() const { return this->playerCount; };

    inline std::string getName() const { return this->name; };

    Grid<PlayerId> &getGrid() { return *this->grid; }

    std::vector<Player> getPlayers() const;

protected:
    /**
     * @brief Construct a new Game object
     *
     * @param name The game name (ex: Tic Tac Toe)
     * @param xSize The grid width
     * @param ySize The grid height
     * @param players  The players list in the game
     * @param positionRequester A unique pointer to a position requester
     * @param gameEvaluator A unique pointer to a game evaluator
     */
    Game(
        const std::string name,
        const std::vector<Player> players,
        std::unique_ptr<PositionRequester> positionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator,
        std::unique_ptr<Grid<PlayerId>> grid);

    std::unique_ptr<PositionRequester> positionRequester;
    std::unique_ptr<GameEvaluator> gameEvaluator;

    /**
     * @brief Play as computer : place his symbol on a free grid position
     *
     * @param playerId  The player id
     */
    virtual Position playAsComputer(const PlayerId &playerId) = 0;

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
    std::unique_ptr<Grid<PlayerId>> grid;

    /**
     * @brief Start playing the next game round
     */
    void nextRound();

    /**
     * @brief Get the next player to play
     *
     * @return Player the player Object who is playing
     */
    Player nextPlayer() const;

    /**
     * @brief Drop the player where has choosen to play
     */
    void dropPlayerOnPosition(const Player &player);

    /**
     * @brief Check if the player has won
     */
    bool checkIfGameFinished(const PlayerId playerId);

    /**
     * @brief End a game with a winner
     *
     * @param playerId
     */
    void win(const PlayerId playerId);

    /**
     * @brief End a game on a tie
     *
     */
    void tie();
};