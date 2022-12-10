#include <iostream>
#include <memory>
#include "game.hpp"
#include "shared/functions.hpp"
#include "models/player.hpp"
#include "games/tictactoe/tictactoe.hpp"
#include "games/power4/power4.hpp"

// Function to ask the user for player selection
unsigned int getPlayerSelection()
{
    shared::printHeader("Choix des joueurs");

    std::cout
        << "1. Contre l'ordinateur" << std::endl;
    std::cout << "2. 2 joueurs" << std::endl;

    std::cout << std::endl
              << "Entrez n'importe quel autre chiffre pour quitter." << std::endl;

    return shared::readInt();
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
    shared::printHeader("Choix du jeu");

    std::cout << "1. Morpion" << std::endl;
    std::cout << "2. Puissance 4" << std::endl
              << std::endl;

    std::cout << "Entrez n'importe quel autre chiffre pour quitter." << std::endl;

    std::cout << "Faites votre choix :" << std::endl;

    return shared::readInt();
}

// Function to create the requested game based on the given game selection
std::unique_ptr<Game> createGame(unsigned int gameSelection, std::vector<Player> players)
{
    if (gameSelection == 1)
    {
        // Create a TicTacToe
        return std::make_unique<TicTacToe>(players, std::make_unique<TicTacToePositionRequester>(), std::make_unique<DefaultGameEvaluator>(3));
    }
    else if (gameSelection == 2)
    {
        // Create a Power4
        return std::make_unique<Power4>(players, std::make_unique<Power4PositionRequester>(), std::make_unique<DefaultGameEvaluator>(4));
    }
    else
    {
        return nullptr;
    }
}

// Function to play the given game
void playGame(std::unique_ptr<Game> game)
{
    game->play();
    shared::printHeader("GAME FINISHED");
}

int main()
{

    while (true)
    {
        // Ask for player selection
        unsigned int playerSelection = getPlayerSelection();

        // Exit if the player selection is invalid
        if (playerSelection > 2)
        {
            return EXIT_SUCCESS;
        }

        // Create players
        std::vector<Player> players = createPlayers(playerSelection);

        // Ask for game selection
        unsigned int gameSelection = getGameSelection();

        // Create the requested game
        std::unique_ptr<Game> game = createGame(gameSelection, players);

        // Launch game
        playGame(std::move(game));
    }
}

