#include "consoleHandler.hpp"

namespace ConsoleHandler
{

    std::string getInput()
    {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    void print(const std::string &output)
    {
        std::cout << output << std::endl;
    }

    void printLine(const std::string &output)
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
                ConsoleHandler::print("Veuillez saisir un chiffre valide.");
            }
        } while (!valid);

        return input;
    }

    void printTitle(const std::string &string)
    {
        ConsoleHandler::print("*-----------------------------*");
        ConsoleHandler::print("     " + string + "     ");
        ConsoleHandler::print("*-----------------------------*");
    }

    void printHeader(const std::string &string)
    {
        ConsoleHandler::print("*** " + string + " ***");
    }

}