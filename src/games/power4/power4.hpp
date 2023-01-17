#pragma once

#include "../../models/player.hpp"
#include "../../interfaces/gameEvaluator.hpp"
#include "../../shared/shared.hpp"
#include "power4Grid.hpp"
#include "../../interfaces/game.hpp"

class Power4 : public Game
{
public:
    Power4(
        const std::vector<Player>& players,
        const std::shared_ptr<PositionRequester> &positionRequester,
        const std::shared_ptr<GameEvaluator> &gameEvaluator)
        : Game("Power 4", players, positionRequester, gameEvaluator, std::make_shared<Power4Grid>())
    {
    }

    Position playAsComputer(const PlayerId &playerId) override;

    static constexpr unsigned int pointsToWin = 4;
};