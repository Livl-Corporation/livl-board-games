#pragma once

#include "../game.hpp"
#include "../models/player.hpp"
#include <vector>

class Power4 : public Game
{
public:
    /**
     * @brief Construct a new Power 4 object
     *
     * @param players
     */
    Power4(std::vector<Player> players) : Game(
                                              "Power 4",
                                              7, 4, 4, players){

                                          };

    /**
     * @brief Ask the player in which column he want to place his symbol
     *
     * @param playerChar
     * @return Cell
     */
    Cell askForCell(const char playerChar) override;

    /**
     * @brief Place a symbol in a available col
     *
     * @param playerId
     * @return Cell
     */
    Cell playAsComputer(int playerId) override;
};