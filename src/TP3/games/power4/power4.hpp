#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "../../shared/shared.hpp"
#include "power4PositionRequester.hpp"
#include "../../shared/evaluators/linearGameEvaluator.hpp"

#include <vector>
#include <memory>

#include "power4Grid.hpp"

class Power4 : public Game
{
public:
    Power4(
        std::vector<Player> players,
        std::unique_ptr<PositionRequester> PositionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Power 4", players, std::move(PositionRequester), std::move(gameEvaluator), std::make_shared<Power4Grid>())
    {
    }

    Position playAsComputer(const PlayerId &playerId) override;

    static constexpr unsigned int pointsToWin = 4;
};