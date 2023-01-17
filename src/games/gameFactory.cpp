#include "gameFactory.hpp"
#include "shared/evaluators/linearGameEvaluator.hpp"

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
        return std::make_unique<Power4>(players, std::make_shared<Power4PositionRequester>(), std::make_shared<LinearGameEvaluator>(Power4::pointsToWin));
    }

    std::unique_ptr<Game> createTicTacToe(const std::vector<Player> &players)
    {
        return std::make_unique<TicTacToe>(players, std::make_shared<TicTacToePositionRequester>(), std::make_shared<LinearGameEvaluator>(TicTacToe::pointsToWin));
    }

    std::unique_ptr<Game> createOthello(const std::vector<Player> &players)
    {
        return std::make_unique<Othello>(players, std::make_shared<OthelloPositionRequester>(), std::make_shared<OthelloGameEvaluator>());
    }

    std::unique_ptr<Game> createCheckers(const std::vector<Player>& players)
    {
        return std::make_unique<Checkers>(players, std::make_shared<CheckersPositionRequester>(), std::make_shared<LinearGameEvaluator>(Checkers::pointsToWin));
    }

    void generatePlayers(int playerSelection, std::vector<Player> &players) {
        Player p1(1, false);
        Player p2(2, playerSelection == 2);
        players.push_back(p1);
        players.push_back(p2);
    }

    void startGame(int gameSelection, int playerSelection) {
        std::vector<Player> players;
        generatePlayers(playerSelection, players);

        auto game = GameFactory::createGame(gameSelection, players);

        if (game != nullptr) {
            game->play();
        }
    }
}