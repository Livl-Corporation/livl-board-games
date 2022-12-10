#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "tictactoeCellRequester.hpp"
#include "../defaults/defaultGameEvaluator.hpp"
#include <vector>
#include <memory>

class TicTacToe : public Game
{
public:
    /**
     * @brief Construct a new TicTacToe object
     *
     * @param players
     * @param cellRequester
     * @param gameEvaluator
     */
    TicTacToe(
        std::vector<Player> players,
        std::unique_ptr<CellRequester> cellRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Tic Tac Toe", xSize, ySize, players, std::move(cellRequester), std::move(gameEvaluator))
    {

    }
private:
    static constexpr unsigned int xSize = 3; // declared as constexpr so that they can be used as compile-time constants.
    static constexpr unsigned int ySize = 3;
};