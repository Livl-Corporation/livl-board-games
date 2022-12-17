#include "consoleHandler.hpp"

namespace ConsoleHandler
{

    std::string getInput()
    {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    void printLine(const std::string &output)
    {
        std::cout << output << std::endl;
    }

    void print(const std::string &output)
    {
        std::cout << output;
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
            catch (const std::exception &e)
            {
                ConsoleHandler::printLine("Veuillez saisir un chiffre valide.");
            }
        } while (!valid);

        return input;
    }

    void printTitle(const std::string &string)
    {
        ConsoleHandler::printLine("*-----------------------------*");
        ConsoleHandler::printLine("     " + string + "     ");
        ConsoleHandler::printLine("*-----------------------------*");
    }

    void printHeader(const std::string &string)
    {
        ConsoleHandler::printLine("*** " + string + " ***");
    }

}