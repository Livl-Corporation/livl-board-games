#include "functions.hpp"

#include <random>

char getPlayerChar(int playerId)
{
    switch (playerId)
    {

    case 1:
        return 'X';

    case 2:
        return 'O';

    default:
        return ' ';
    }
}

int randomInt(int min, int max)
{

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);

    return uni(rng);
}