#include "gameFactory.hpp"

namespace GameFactory
{
    std::unique_ptr<Game> createPower4(const std::vector<Player> &players)
    {
        return std::make_unique<Power4>(players, std::make_unique<Power4PositionRequester>(), std::make_unique<LinearGameEvaluator>(Power4::pointsToWin));
    };

    std::unique_ptr<Game> createTicTacToe(const std::vector<Player> &players)
    {
        return std::make_unique<TicTacToe>(players, std::make_unique<TicTacToePositionRequester>(), std::make_unique<LinearGameEvaluator>(TicTacToe::pointsToWin));
    };
}