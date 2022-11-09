#pragma once

#include "../game.hpp"
#include "../player.hpp"
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
                                                 "Morpion",
                                                 3, 3, 3, players){

                                             };
};