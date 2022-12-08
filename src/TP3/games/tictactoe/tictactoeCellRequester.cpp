#include "tictactoeCellRequester.hpp"

Cell TicTacToeCellRequester::askForCell(const char playerChar, const Grid &grid)
{
    std::cout << "Où voulez vous placer votre pion (" << playerChar << ") entre 1,1 et " << grid.getXSize() << "," << grid.getYSize() << " ?" << std::endl;

    unsigned int x, y;
    scanf("%d,%d", &x, &y);
    return {x : x - 1, y : y - 1};
}