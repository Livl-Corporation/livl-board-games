#include "functions.hpp"

namespace shared {
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
            try
            {
                input = std::stoi(ConsoleHandler::getInput());
                valid = true;
            }
            catch (const std::exception& e)
            {
                ConsoleHandler::printOutput("Veuillez saisir un chiffre valide.");
            }
        } while (!valid);

        return input;
    }

    void printTitle(const std::string &string)
    {
        ConsoleHandler::printOutput("*-----------------------------*");
        ConsoleHandler::printOutput("     " + string + "     ");
        ConsoleHandler::printOutput("*-----------------------------*");
    }

    void printHeader(const std::string &string)
    {
        ConsoleHandler::printOutput("*** " + string + " ***");
    }
}