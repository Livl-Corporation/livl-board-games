#pragma once

#include <memory>
#include <vector>

#include "../models/player.hpp"

#include "../game.hpp"

#include "tictactoe/tictactoe.hpp"
#include "tictactoe/tictactoePositionRequester.hpp"

#include "power4/power4.hpp"
#include "power4/power4PositionRequester.hpp"

#include "othello/othello.hpp"

#include "../shared/evaluators/linearGameEvaluator.hpp"

namespace GameFactory
{
    std::unique_ptr<Game> createGame(const unsigned int gameId, const std::vector<Player> &players);
    std::unique_ptr<Game> createPower4(const std::vector<Player> &players);
    std::unique_ptr<Game> createTicTacToe(const std::vector<Player> &players);
    std::unique_ptr<Game> createOthello(const std::vector<Player> &players);

}