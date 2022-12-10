#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "../../shared/functions.hpp"
#include "power4CellRequester.hpp"
#include "../defaults/defaultGameEvaluator.hpp"
#include <vector>
#include <memory>

class Power4 : public Game
{
public:
      /**
     * @brief Construct a new Power 4 object
     *
     * @param players
     * @param cellRequester A unique pointer to a cell requester
     * @param gameEvaluator A unique pointer to a game evaluator
     */
    Power4(
        std::vector<Player> players,
        std::unique_ptr<CellRequester> cellRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Power 4", 7, 4, players, std::move(cellRequester), std::move(gameEvaluator))
    {
        // other initializations
    }

    /**
     * @brief Place a symbol in a available col
     *
     * @param playerId
     * @return Cell
     */
    Cell playAsComputer(const unsigned int &playerId) override;
};