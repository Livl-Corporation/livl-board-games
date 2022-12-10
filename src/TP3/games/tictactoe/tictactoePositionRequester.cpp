#include "tictactoePositionRequester.hpp"

Position TicTacToePositionRequester::askForPosition(const char playerChar, const Grid &grid) const
{
    std::cout << "Où voulez vous placer votre pion (" << playerChar << ") entre 1,1 et " << grid.getXSize() << "," << grid.getYSize() << " ?" << std::endl;

    unsigned int x, y;
    int scanfResult = 0;
    do {
        // Read the input as a string and check for the comma separator
        std::string input;
        std::cin >> input;
        if (input.find(',') != std::string::npos) { // std::string::npos is returned if no comma is found
            // If the comma separator is found, use sscanf to parse the x and y values
            scanfResult = sscanf(input.c_str(), "%d,%d", &x, &y);
        } else {
            // Otherwise, reset the scanfResult to 0
            scanfResult = 0;
        }

        if (scanfResult != 2) {
            std::cout << "Entrée invalide. Veuillez entrer deux nombres séparés par une virgule." << std::endl;
        }
    } while (scanfResult != 2);

    return {x : x - 1, y : y - 1};
}