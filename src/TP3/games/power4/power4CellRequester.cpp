#include "power4CellRequester.hpp"

Cell Power4CellRequester::askForCell(const char playerChar, const Grid &grid) const
{
    unsigned int col, row;

    do
    {

        std::cout << "Dans quelle colonne souhaitez vous jouer ? (1-" << grid.getXSize() << ")" << std::endl;

        col = shared::readInt();

        // Check if the column is valid
        if (col < 1 || col > grid.getXSize())
        {
            std::cout << "Veuillez entrer une colonne entre 1 et " << grid.getXSize() << "." << std::endl;
        }
        else
        {
            // Get first y position available in this col
            try
            {
                row = grid.firstRowAvailableInCol(col - 1);

                // if the previous functions has not thrown any error, we have a valid cell
                return {x : col - 1, y : row};
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    } while (true);
}
