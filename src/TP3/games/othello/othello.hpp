#pragma once

#include "../../game.hpp"
#include "../../models/player.hpp"
#include "../../shared/shared.hpp"

#include <vector>
#include <memory>

#include "othelloGrid.hpp"

class Othello : public Game
{
public:
    Othello(
        std::vector<Player> players,
        std::unique_ptr<PositionRequester> PositionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Othello", players, std::move(PositionRequester), std::move(gameEvaluator), std::make_unique<OthelloGrid>())
    {
    }

    virtual void afterPlacementAction(const PlayerId &playerId, const Position position) override;

    Position playAsComputer(const PlayerId &playerId) override;
};