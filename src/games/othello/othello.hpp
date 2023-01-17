#pragma once

#include "../../interfaces/game.hpp"
#include "othelloGameEvaluator.hpp"
#include "othelloGrid.hpp"

class Othello : public Game
{
public:
    Othello(
        const std::vector<Player>& players,
        const std::shared_ptr<PositionRequester> &positionRequester,
        const std::shared_ptr<GameEvaluator> &gameEvaluator)
        : Game( "Othello", players, positionRequester, gameEvaluator, std::make_shared<OthelloGrid>())
    {
    }

    void afterPlacementAction(const PlayerId &playerId, const Position &position) override;
    Position playAsComputer(const PlayerId &playerId) override;

private:
    void flipPieces(const Position &pos, PlayerId playerId);
};