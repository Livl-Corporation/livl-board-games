#include "power4.hpp"

Position Power4::playAsComputer(const PlayerId &playerId)
{

    unsigned int col, row = 0;

    do
    {
        col = Shared::randomInt(0, this->getGrid().getXSize() - 1);

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