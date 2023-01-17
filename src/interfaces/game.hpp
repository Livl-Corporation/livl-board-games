#pragma once

#include <string>
#include <memory>
#include <vector>
#include "positionRequester.hpp"
#include "../models/player.hpp"
#include "gameEvaluator.hpp"

class Game
{
public:
    virtual ~Game() = default;

    /**
     * @brief Start the game
     */
    void play();

    [[nodiscard]] inline unsigned int getRound() const { return this->round; };

    [[nodiscard]] inline std::string getName() const { return this->name; };

    [[nodiscard]] std::shared_ptr<Grid<PlayerId>> getGrid() const { return this->grid; }

    [[nodiscard]] std::vector<Player> getPlayers() const;

protected:
    Game(
        std::string  name,
        const std::vector<Player>& players,
        std::unique_ptr<PositionRequester> positionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator,
        std::shared_ptr<Grid<PlayerId>> grid);

    std::unique_ptr<PositionRequester> positionRequester;

    std::unique_ptr<GameEvaluator> gameEvaluator;

    virtual Position playAsComputer(const PlayerId &playerId) = 0;

    virtual void afterPlacementAction(const PlayerId &playerId, const Position &position){};

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

    [[nodiscard]] PlayerId getPlayerId(unsigned int roundNumber) const;

    [[nodiscard]] Player getNextPlayer();

    void playerChoosePosition(const PlayerId &playerId, bool isComputer);

    void endGame();
};