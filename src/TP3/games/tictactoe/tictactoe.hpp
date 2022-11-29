#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "tictactoeCellRequester.hpp"
#include "../defaults/defaultGameEvaluator.hpp"
#include <vector>

class TicTacToe : public Game
{
public:
    /**
     * @brief Construct a new Tic Tac Toe object
     *
     * @param players
     */
    TicTacToe(std::vector<Player> players) : Game(
                                                 "TicTacToe",
                                                 3, 3,
                                                 players)
    {
        this->cellRequester = new TicTacToeCellRequester(this->getGrid());
        this->gameEvaluator = new DefaultGameEvaluator(3);
    };
};