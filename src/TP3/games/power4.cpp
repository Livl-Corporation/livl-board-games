#include "power4.hpp"
#include "../models/cell.hpp"
#include "../shared/functions.hpp"

#include "../shared/exceptions/out-of-bounds-exception.hpp"

#include <iostream>
#include <vector>
#include <stdlib.h>

Cell Power4::askForCell(const char playerChar)
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
                          << "Veuillez entrer une colonne entre 1 et " << this->getGrid().getXSize() << "." << std::endl;
            }

            std::cout << "Dans quelle colonne souhaitez vous jouer ? (1-" << this->getGrid().getXSize() << ")" << std::endl;

            col = readInt();
            alreadyAsked = true;

        } while (col < 1 || col > this->getGrid().getXSize());

        col--;

        // Get first y position available in this col
        try
        {
            row = this->getGrid().firstRowAvailableInCol(col);

            // if the previous functions has not thrown any error, we have a valid cell
            validCell = true;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

    } while (!validCell);

    Cell cell{x : col, y : row};
    return cell;
}

Cell Power4::playAsComputer(int playerId)
{

    unsigned int col, row = 0;

    do
    {
        col = randomInt(0, this->getGrid().getXSize() - 1);

        try
        {
            row = this->getGrid().firstRowAvailableInCol(col);
        }
        catch (...)
        {
        }

    } while (!this->getGrid().place({col, row}, playerId));

    return {col, row};
}