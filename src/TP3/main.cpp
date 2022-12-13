#include <memory>
#include "game.hpp"
#include "shared/consoleHandler.hpp"
#include "models/player.hpp"
#include "games/gameFactory.hpp"

// Function to ask the user for player selection
unsigned int getPlayerSelection()
{
    ConsoleHandler::printHeader("Choix des joueurs");

    ConsoleHandler::printOutput("1. Contre l'ordinateur");
    ConsoleHandler::printOutput("2. 2 joueurs");
    ConsoleHandler::printOutput("\nEntrez n'importe quel autre chiffre pour quitter.");

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
    ConsoleHandler::printHeader("Choix du jeu");
    ConsoleHandler::printOutput("1. Morpion");
    ConsoleHandler::printOutput("2. Puissance 4");
    ConsoleHandler::printOutput("\nEntrez n'importe quel autre chiffre pour quitter.");
    ConsoleHandler::printOutput("Faites votre choix :");
    return ConsoleHandler::readInt();
}

// Function to create the requested game based on the given game selection
std::unique_ptr<Game> createGame(unsigned int gameSelection, const std::vector<Player> &players)
{
    if (gameSelection == 1)
    {
        return GameFactory::createTicTacToe(players);
    }
    else if (gameSelection == 2)
    {
        return GameFactory::createPower4(players);
    }

    return nullptr;
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
        std::unique_ptr<Game> game = createGame(gameSelection, players);

        if (!game)
            return EXIT_SUCCESS; // if return nullptr, exit

        // Launch game
        playGame(std::move(game));
    }
}
