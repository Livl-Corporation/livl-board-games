#pragma once

#include "../game.hpp"
#include "../models/player.hpp"
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
                                                 3, 3, 3, players){

                                             };
};