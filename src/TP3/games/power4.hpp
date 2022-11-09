#pragma once

#include "../game.hpp"
#include "../player.hpp"
#include <vector>

class Power4 : public Game
{
public:
    Power4(std::vector<Player> players) : Game(
                                              "Puissance 4",
                                              7, 4, 4, players){

                                          };
};