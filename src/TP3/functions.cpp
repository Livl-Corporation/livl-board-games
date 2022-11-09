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