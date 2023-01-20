#include "player.hpp"

char Player::getPlayerChar(PlayerId playerId)
{
    switch (playerId)
    {
    case 1:
        return 'x';

    case 2:
        return 'o';

    default:
        return ' ';
    }
}