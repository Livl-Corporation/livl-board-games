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

    std::shared_ptr<Grid<PlayerId>> getGrid() const { return this->grid; }

    std::vector<Player> getPlayers() const;

protected:
    Game(
        const std::string name,
        const std::vector<Player> players,
        std::unique_ptr<PositionRequester> positionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator,
        std::shared_ptr<Grid<PlayerId>> grid);

    std::unique_ptr<PositionRequester> positionRequester;

    std::unique_ptr<GameEvaluator> gameEvaluator;

    virtual Position playAsComputer(const PlayerId &playerId) = 0;

    virtual void afterPlacementAction(const PlayerId &playerId, const Position position){};

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
     * @brief The number of players playing
     */
    unsigned int playerCount = 0;

    /**
     * @brief The players list in the game
     */
    std::vector<Player> players;

    /**
     * @brief The grid of the game
     */
    std::shared_ptr<Grid<PlayerId>> grid;

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

    void playerChoosePosition(const PlayerId playerId, const bool isComputer);

    void endGame();
};