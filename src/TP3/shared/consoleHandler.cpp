#include "consoleHandler.hpp"

std::string ConsoleHandler::getInput()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void ConsoleHandler::printOutput(const std::string& output)
{
    std::cout << output << std::endl;
}

void ConsoleHandler::printOutputWithoutNewLine(const std::string& output)
{
    std::cout << output;
}