#include "power4CellRequester.hpp"

Cell Power4CellRequester::askForCell(const char playerChar, const Grid &grid)
{
    bool alreadyAsked = false;
    unsigned int col, row;
    bool validCell = false;

    do
    {

        // Ask for a valid column
        do
        {
            if (alreadyAsked)
            {
                std::cout << std::endl
                          << "Veuillez entrer une colonne entre 1 et " << grid.getXSize() << "." << std::endl;
            }

            std::cout << "Dans quelle colonne souhaitez vous jouer ? (1-" << grid.getXSize() << ")" << std::endl;

            col = readInt();
            alreadyAsked = true;

        } while (col < 1 || col > grid.getXSize());

        col--;

        // Get first y position available in this col
        try
        {
            row = grid.firstRowAvailableInCol(col);

            // if the previous functions has not thrown any error, we have a valid cell
            validCell = true;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

    } while (!validCell);

    return {x : col, y : row};
}