#include "functions.hpp"

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

int readInt()
{

    int input;
    bool valid = false;

    do
    {
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Veuillez saisir un chiffre." << std::endl;
        }
        else
        {
            valid = true;
        }
    } while (!valid);

    return input;
}

void printTitle(const std::string &string)
{
    std::cout << std::endl
              << "*-----------------------------*" << std::endl;
    std::cout << "     " << string << "     " << std::endl;
    std::cout << "*-----------------------------*" << std::endl;
}

void printHeader(const std::string &string)
{
    std::cout << std::endl
              << "*** " << string << " ***" << std::endl
              << std::endl;
}