#pragma once

#include "../../shared/shared.hpp"
#include "../../interfaces/game.hpp"
#include "../../models/player.hpp"
#include "tictactoeGrid.hpp"

class TicTacToe : public Game
{
public:
    TicTacToe(
        const std::vector<Player>& players,
        std::unique_ptr<PositionRequester> positionRequester,
        std::unique_ptr<GameEvaluator> gameEvaluator)
        : Game("Tic Tac Toe", players, std::move(positionRequester), std::move(gameEvaluator), std::make_shared<TicTacToeGrid>())
    {
    }

    Position playAsComputer(const PlayerId &playerId) override;

    static constexpr unsigned int pointsToWin = 3;
};