#include "power4PositionRequester.hpp"

Position Power4PositionRequester::askForPosition(const char playerChar, const Grid &grid) const
{
    unsigned int col, row;

    do
    {
        ConsoleHandler::printOutput("Dans quelle colonne souhaitez vous jouer ? (1-" + std::to_string(grid.getXSize()) + ")");

        try
        {
            col = std::stoi(ConsoleHandler::getInput());
        }
        catch (const std::exception &e)
        {
            ConsoleHandler::printOutput("Veuillez entrer un nombre entier valide.");
            continue;
        }

        // Check if the column is valid
        if (col < 1 || col > grid.getXSize())
        {
            ConsoleHandler::printOutput("Veuillez entrer une colonne entre 1 et " + std::to_string(grid.getXSize()) + ".");
        }
        else
        {
            // Get first y position available in this col
            try
            {
                row = grid.firstRowAvailableInCol(col - 1);

                // if the previous functions has not thrown any error, we have a valid Position
                return {x : col - 1, y : row};
            }
            catch (const std::exception &e)
            {
                ConsoleHandler::printOutput(e.what());
            }
        }
    } while (true);
}
