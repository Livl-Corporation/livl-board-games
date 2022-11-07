#include <iostream>

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

        if (selectedGame == 1) {
            // Launch TicTacToe
        } else if (selectedGame == 2) {
            // Launch Power4
        } else {
            // Exit
            return EXIT_SUCCESS;
        }

    }

}