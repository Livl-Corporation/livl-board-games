#include <memory>
#include "interfaces/game.hpp"
#include "shared/consoleHandler.hpp"
#include "models/player.hpp"
#include "games/gameFactory.hpp"

// Function to ask the user for player selection
unsigned int getPlayerSelection()
{
    ConsoleHandler::printHeader("GAME MODE");
    ConsoleHandler::printLine("1. Against the computer");
    ConsoleHandler::printLine("2. 2 players");
    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");

    return ConsoleHandler::readInt();
}

// Function to create players based on the given player selection
std::vector<Player> createPlayers(unsigned int playerSelection)
{
    std::vector<Player> players;
    Player p1(1, false);
    Player p2(2, playerSelection == 1);
    players.push_back(p1);
    players.push_back(p2);
    return players;
}

// Function to ask the user for game selection
unsigned int getGameSelection()
{
    ConsoleHandler::printLine("");
    ConsoleHandler::printHeader("BOARD GAME CHOICE");
    ConsoleHandler::printLine("1. Tic-Tac-Toe");
    ConsoleHandler::printLine("2. Power 4");
    ConsoleHandler::printLine("3. Othello");
    ConsoleHandler::printLine("Enter any other number to exit.\n");
    ConsoleHandler::print("Choice : n°");
    return ConsoleHandler::readInt();
}

// Function to play the given game
void playGame(std::unique_ptr<Game> game)
{
    game->play();
    ConsoleHandler::printHeader("GAME FINISHED");
}

int main()
{
    while (true)
    {
        // Ask for player selection
        unsigned int playerSelection = getPlayerSelection();

        // Exit if the player selection is invalid
        if (playerSelection > 2 || playerSelection < 1)
            return EXIT_SUCCESS;

        // Create players
        std::vector<Player> players = createPlayers(playerSelection);

        // Ask for game selection
        unsigned int gameSelection = getGameSelection();

        // Create the requested game
        std::unique_ptr<Game> game = GameFactory::createGame(gameSelection, players);

        if (!game)
            return EXIT_SUCCESS; // if return nullptr, exit

        // Launch game
        playGame(std::move(game));
    }
}
