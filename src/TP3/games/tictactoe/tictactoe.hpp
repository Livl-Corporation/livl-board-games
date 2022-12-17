#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "tictactoePositionRequester.hpp"
#include "../../shared/evaluators/linearGameEvaluator.hpp"

#include <vector>
#include <memory>

#include "tictactoeGrid.hpp"

class TicTacToe : public Game
{
public:
    /**
     * @brief Construct a new TicTacToe object
     *
     * @param players
     * @param positionRequester
     * @param gameEvaluator
     */
    TicTacToe(
        std::vector<Player> players,
        std::unique_ptr<PositionRequester> positionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Tic Tac Toe", players, std::move(positionRequester), std::move(gameEvaluator), std::make_unique<TicTacToeGrid>())
    {
    }

    /**
     * @brief Place a symbol in a available col
     *
     * @param playerId
     * @return position
     */
    Position playAsComputer(const PlayerId &playerId) override;

    static constexpr unsigned int pointsToWin = 3;

private:
    static constexpr unsigned int xSize = 3; // declared as constexpr so that they can be used as compile-time constants.
    static constexpr unsigned int ySize = 3;
};