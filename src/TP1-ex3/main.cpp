#include <iostream>
#include "functions.hpp"

int main()
{

    std::cout << "Bonjour ! Quel est votre prénom ?" << std::endl;

    std::string name;
    std::cin >> name;

    std::cout << "Bonjour, " << name << std::endl;

    return 0;
}