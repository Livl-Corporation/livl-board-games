#include "gameFactory.hpp"

namespace GameFactory
{

    std::unique_ptr<Game> createGame(const unsigned int gameId, const std::vector<Player> &players)
    {
        switch (gameId)
        {
            case 1:
                return GameFactory::createTicTacToe(players);
            case 2:
                return GameFactory::createPower4(players);
            case 3:
                return GameFactory::createOthello(players);
            case 4:
                return GameFactory::createCheckers(players);
            default:
                return nullptr;
        }
    }

    std::unique_ptr<Game> createPower4(const std::vector<Player> &players)
    {
        return std::make_unique<Power4>(players, std::make_unique<Power4PositionRequester>(), std::make_unique<LinearGameEvaluator>(Power4::pointsToWin));
    }

    std::unique_ptr<Game> createTicTacToe(const std::vector<Player> &players)
    {
        return std::make_unique<TicTacToe>(players, std::make_unique<TicTacToePositionRequester>(), std::make_unique<LinearGameEvaluator>(TicTacToe::pointsToWin));
    }

    std::unique_ptr<Game> createOthello(const std::vector<Player> &players)
    {
        return std::make_unique<Othello>(players, std::make_unique<OthelloPositionRequester>(), std::make_unique<OthelloGameEvaluator>());
    }

    std::unique_ptr<Game> createCheckers(const std::vector<Player>& players)
    {
        return std::make_unique<Checkers>(players, std::make_unique<CheckersPositionRequester>(), std::make_unique<LinearGameEvaluator>(Checkers::pointsToWin));
    }

}
