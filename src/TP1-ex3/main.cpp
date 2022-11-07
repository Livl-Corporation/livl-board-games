#include <iostream>
#include "functions.hpp"

int main()
{

    std::string firstname;
    std::string lastname;

    std::cout << "Bonjour ! Quel est votre nom et prénom ?" << std::endl;

    std::cin >> firstname >> lastname;
    capitalize(firstname);
    toUpper(lastname);

    std::cout << "Bonjour, " << firstname << " " << lastname << std::endl;

    return 0;
}