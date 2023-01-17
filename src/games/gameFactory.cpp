#include "gameFactory.hpp"

namespace GameFactory
{

    std::unique_ptr<Game> createGame(const unsigned int gameId, const std::vector<Player> &players)
    {

        if (gameId == 1)
        {
            return createTicTacToe(players);
        }
        else if (gameId == 2)
        {
            return createPower4(players);
        }
        else if (gameId == 3)
        {
            return createOthello(players);
        }

        return nullptr;
    }

    std::unique_ptr<Game> createPower4(const std::vector<Player> &players)
    {
        ConsoleHandler::printLine("keyy");
        return std::make_unique<Power4>(players, std::make_shared<Power4PositionRequester>(), std::make_shared<LinearGameEvaluator>(Power4::pointsToWin));
    }

    std::unique_ptr<Game> createTicTacToe(const std::vector<Player> &players)
    {
        return std::make_unique<TicTacToe>(players, std::make_shared<TicTacToePositionRequester>(), std::make_shared<LinearGameEvaluator>(TicTacToe::pointsToWin));
    }

    std::unique_ptr<Game> createOthello(const std::vector<Player> &players)
    {
        return std::make_unique<Othello>(players, std::make_unique<OthelloPositionRequester>(), std::make_unique<OthelloGameEvaluator>());
    }

    void generatePlayers(int playerSelection, std::vector<Player> &players) {
        Player p1(1, false);
        Player p2(2, playerSelection == 1);
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