#include <iostream>
#include "functions.hpp"

int main()
{

    int nb1 = 3;
    int nb2 = 11;

    std::cout << "Somme de " << nb1 << " et " << nb2 << " = " << somme(nb1, nb2) << std::endl;

    std::cout << "Inversion de " << nb1 << " et " << nb2 << "..." << std::endl;

    inverser(nb1, nb2);

    std::cout << "Résultat : " << nb1 << " et " << nb2 << std::endl;

    int nb3 = 2;

    std::cout << "Remplacer par la somme de " << nb1 << ", " << nb2 << " et " << nb3 << std::endl;
    replaceBySum(nb1, nb2, nb3);
    std::cout << "Résultat : " << nb1 << ", " << nb2 << " et " << nb3 << std::endl;

    nb3 = 2;

    std::cout << "Remplacer par la somme (avec les pointeurs) de " << nb1 << ", " << nb2 << " et " << nb3 << std::endl;
    replaceBySum(&nb1, &nb2, &nb3);
    std::cout << "Résultat : " << nb1 << ", " << nb2 << " et " << nb3 << std::endl;

    std::cout << "Entrez la taille du tableau que vous souhaitez générer : ";

    int arraySize;
    std::cin >> arraySize;

    std::cout << "Génération d'un tableau de " << arraySize << " éléments" << std::endl;

    int array[arraySize];
    fillArrayWithInt(array, arraySize);

    std::cout << "Affichage du tableau :" << std::endl;

    printArray(array, arraySize);

    bool isAscSort;
    std::cout << "Dans quel ordre souhaitez vous trier le tableau ?" << std::endl;
    std::cout << "0 : Décroissant" << std::endl;
    std::cout << "1 : Croissant" << std::endl;

    std::cin >> isAscSort;

    std::cout << "Tri du tableau ..." << std::endl;

    sortArray(array, arraySize, isAscSort);

    printArray(array, arraySize);

    std::cout << "Inversion du tableau ..." << std::endl;

        return 0;
}