#include <iostream>
#include "functions.hpp"

int main()
{

    std::cout << "Bonjour" << std::endl;

    int nombre = rand() % 1000;
    int compteur = 0;

    int entree = -1;

    while (entree != nombre)
    {
        compteur++;
        std::cout << "Entrez un nombre : " << std::endl;
        std::cin >> entree;

        if (entree > nombre)
        {
            std::cout << "C'est plus petit !" << std::endl;
        }
        else if (entree < nombre)
        {
            std::cout << "C'est plus grand !" << std::endl;
        }
    }

    std::cout << "Bravo ! Le nombre était bien " << nombre << std::endl
              << "Vous l'avez trouvé en " << compteur << " essais" << std::endl;

    return 0;
}