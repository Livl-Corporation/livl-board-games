#include "player.hpp"

char Player::getPlayerChar(PlayerId playerId)
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