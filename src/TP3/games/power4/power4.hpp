#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "../../shared/shared.hpp"
#include "power4PositionRequester.hpp"
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
     * @param PositionRequester A unique pointer to a Position requester
     * @param gameEvaluator A unique pointer to a game evaluator
     */
    Power4(
        std::vector<Player> players,
        std::unique_ptr<PositionRequester> PositionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Power 4", xSize, ySize, players, std::move(PositionRequester), std::move(gameEvaluator))
    {
        // other initializations
    }

    /**
     * @brief Place a symbol in a available col
     *
     * @param playerId
     * @return position
     */
    Position playAsComputer(const PlayerId &playerId) override;

private:
    static constexpr unsigned int xSize = 7; // declared as constexpr so that they can be used as compile-time constants.
    static constexpr unsigned int ySize = 4;
};