#include "power4.hpp"

Cell Power4::playAsComputer(const unsigned int playerId)
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