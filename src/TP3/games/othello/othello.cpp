#include "othello.hpp"

Position Othello::playAsComputer(const PlayerId &playerId)
{

    unsigned int col, row = 0;

    do
    {
        col = Shared::randomInt(0, this->getGrid().getXSize() - 1);

        try
        {
            Power4Grid p4grid = static_cast<Power4Grid>(this->getGrid());
            row = p4grid.firstRowAvailableInCol(col);
        }
        catch (...)
        {
        }

    } while (!this->getGrid().place({col, row}, playerId));

    return {col, row};
}