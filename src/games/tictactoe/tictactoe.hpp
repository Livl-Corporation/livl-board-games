#pragma once

#include "../../interfaces/game.hpp"
#include "../../models/player.hpp"
#include "shared/shared.hpp"
#include "tictactoeGrid.hpp"

class TicTacToe : public Game
{
public:
    TicTacToe(
        const std::vector<Player>& players,
        const std::shared_ptr<PositionRequester> &positionRequester,
        const std::shared_ptr<GameEvaluator> &gameEvaluator)
        : Game("Tic Tac Toe", players, positionRequester, gameEvaluator, std::make_shared<TicTacToeGrid>())
    {
    }

    Position playAsComputer(const PlayerId &playerId) override;

    static constexpr unsigned int pointsToWin = 3;
};