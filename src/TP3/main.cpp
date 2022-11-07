#include <iostream>
#include "game.hpp"
#include "games/tictactoe.hpp"
#include "games/power4.hpp"

int main()
{

    while(true) {

        std::cout << "*** Choix du jeu ***" << std::endl << std::endl;

        std::cout << "1. Morpion" << std::endl;
        std::cout << "2. Puissance 4" << std::endl << std::endl;

        std::cout << "Entrez n'importe quel autre chiffre pour quitter." << std::endl;

        std::cout << "Faites votre choix :" << std::endl;

        unsigned int selectedGame;
        std::cin >> selectedGame;

        if (selectedGame > 2) {
            // Exit
            return EXIT_SUCCESS;
        }

        Game* game;
        if (selectedGame == 1) {
            // Create a TicTacToe
            game = new TicTacToe();
        } else if (selectedGame == 2) {
            // Create a Power4
            game = new Power4();
        } 

        // Lauch game 
        game->play();

        std::cout << "*** GAME FINISHED ***" << std::endl;

    }

}