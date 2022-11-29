#include <iostream>
#include "game.hpp"
#include "shared/functions.hpp"
#include "models/player.hpp"
#include "games/tictactoe/tictactoe.hpp"
#include "games/power4/power4.hpp"

int main()
{

    while (true)
    {

        // Ask for player selection

        printHeader("Choix des joueurs");

        std::cout
            << "1. Contre l'ordinateur" << std::endl;
        std::cout << "2. 2 joueurs" << std::endl;

        std::cout << std::endl
                  << "Entrez n'importe quel autre chiffre pour quitter." << std::endl;

        unsigned int playerSelection = readInt();

        if (playerSelection > 2)
        {
            // Exit
            return EXIT_SUCCESS;
        }

        // Create players

        std::vector<Player> players;
        Player p1(1, false);
        Player p2(2, playerSelection == 1);
        players.push_back(p1);
        players.push_back(p2);

        // Ask for game selection

        printHeader("Choix du jeu");

        std::cout << "1. Morpion" << std::endl;
        std::cout << "2. Puissance 4" << std::endl
                  << std::endl;

        std::cout << "Entrez n'importe quel autre chiffre pour quitter." << std::endl;

        std::cout << "Faites votre choix :" << std::endl;

        unsigned int gameSelection = readInt();

        if (gameSelection > 2)
        {
            // Exit
            return EXIT_SUCCESS;
        }

        // Create requested game
        Game *game;
        if (gameSelection == 1)
        {
            // Create a TicTacToe
            game = new TicTacToe(players);
        }
        else if (gameSelection == 2)
        {
            // Create a Power4
            game = new Power4(players);
        }

        // Lauch game
        game->play();

        delete game;

        printHeader("GAME FINISHED");
    }
}