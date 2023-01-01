#pragma once

#include "../../interfaces/game.hpp"
#include "../../models/player.hpp"
#include "../../shared/shared.hpp"

#include <vector>
#include <memory>

#include "othelloGrid.hpp"

class Othello : public Game
{
public:
    Othello(
        const std::vector<Player>& players,
        std::unique_ptr<PositionRequester> PositionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Othello", players, std::move(PositionRequester), std::move(gameEvaluator), std::make_shared<OthelloGrid>())
    {
    }

    void afterPlacementAction(const PlayerId &playerId, const Position &position) override;
    Position playAsComputer(const PlayerId &playerId) override;

private:
    void flipPieces(const Position &pos, PlayerId playerId);
};