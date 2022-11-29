#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "../../shared/functions.hpp"
#include "power4CellRequester.hpp"
#include "../defaults/defaultGameEvaluator.hpp"
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
                                              7, 4,
                                              players)
    {
        this->cellRequester = new Power4CellRequester(this->getGrid());
        this->gameEvaluator = new DefaultGameEvaluator(4);
    };

    /**
     * @brief Place a symbol in a available col
     *
     * @param playerId
     * @return Cell
     */
    Cell playAsComputer(const unsigned int playerId) override;
};