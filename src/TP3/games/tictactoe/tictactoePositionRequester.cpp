#include "tictactoePositionRequester.hpp"

Position TicTacToePositionRequester::askForPosition(const char playerChar, const Grid<PlayerId> &grid) const
{
    std::string outputAskPlayer = "Où voulez vous placer votre pion (";
    outputAskPlayer += playerChar;
    outputAskPlayer += ") entre 1,1 et " + std::to_string(grid.getXSize()) + "," + std::to_string(grid.getYSize()) + " ?";

    ConsoleHandler::print(outputAskPlayer);

    unsigned int x, y;
    int scanfResult = 0;
    do
    {
        // Read the input as a string and check for the comma separator
        std::string input = ConsoleHandler::getInput();
        if (input.find(',') != std::string::npos)
        { // std::string::npos is returned if no comma is found
            // If the comma separator is found, use sscanf to parse the x and y values
            scanfResult = sscanf(input.c_str(), "%d,%d", &x, &y);
        }
        else
        {
            // Otherwise, reset the scanfResult to 0
            scanfResult = 0;
        }

        if (scanfResult != 2)
        {
            ConsoleHandler::print("Entrée invalide. Veuillez entrer deux nombres séparés par une virgule.");
        }
    } while (scanfResult != 2);

    return {(x - 1), (y - 1)};
}