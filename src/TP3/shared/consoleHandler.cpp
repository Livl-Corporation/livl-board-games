#include "consoleHandler.hpp"

namespace ConsoleHandler
{

    std::string getInput()
    {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    void printOutput(const std::string &output)
    {
        std::cout << output << std::endl;
    }

    void printOutputWithoutNewLine(const std::string &output)
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