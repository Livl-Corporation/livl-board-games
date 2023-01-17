#pragma once

#include "../../interfaces/game.hpp"
#include "../../models/player.hpp"
#include "../../shared/shared.hpp"

#include <memory>
#include <vector>

#include "checkersGrid.hpp"

class Checkers : public Game
{
public:
    Checkers(
            const std::vector<Player>& players,
            const std::shared_ptr<PositionRequester>& positionRequester,
            const std::shared_ptr<GameEvaluator>& gameEvaluator)
            : Game("Checkers", players, positionRequester, gameEvaluator, std::make_shared<CheckersGrid>())
    {
    }

    Position playAsComputer(const PlayerId &playerId) override;

    static constexpr unsigned int pointsToWin = 12;
};
