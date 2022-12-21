#include "power4.hpp"

Position Power4::playAsComputer(const PlayerId &playerId)
{
    int col, row = 0;

    col = Shared::randomInt(0, this->getGrid()->getXSize() - 1);

    try
    {
        Power4Grid p4grid = static_cast<Power4Grid>(*this->getGrid());
        row = p4grid.firstRowAvailableInCol(col);
    }
    catch (...)
    {
    }

    return {col, row};
}