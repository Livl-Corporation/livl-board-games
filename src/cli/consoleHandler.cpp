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
                ConsoleHandler::printLine("Please enter a valid number.");
            }
        } while (!valid);

        return input;
    }

    std::vector<int> readValues(int numValues)
    {
        std::vector<int> values;
        do
        {
            // Read the input as a string
            std::string input;
            std::getline(std::cin, input);

            // Use a string stream to parse the input and extract the values
            std::stringstream inputStream(input);
            for (int i = 0; i < numValues; i++)
            {
                std::string valueStr;
                if (std::getline(inputStream, valueStr, ','))
                {
                    int value;
                    std::stringstream(valueStr) >> value;
                    values.push_back(value);
                }
                else
                {
                    break;
                }
            }

            if (values.size() != numValues)
            {
                ConsoleHandler::printLine("Invalid input. Please enter " + std::to_string(numValues) + " values separated by commas.");
                values.clear();
            }
        } while (values.size() != numValues);

        return values;
    }

    void printTitle(const std::string &string)
    {
        // Calculate the length of the string
        size_t stringLength = string.length();

        // Calculate left and right spacing
        size_t leftSpacing = (30 - stringLength) / 2;
        size_t rightSpacing = 30 - stringLength - leftSpacing;

        ConsoleHandler::printLine("\n*------------------------------*");
        ConsoleHandler::print("*");

        for (size_t i = 0; i < leftSpacing; i++)
            ConsoleHandler::print(" ");
        ConsoleHandler::print(string);

        for (size_t i = 0; i < rightSpacing; i++)
            ConsoleHandler::print(" ");
        ConsoleHandler::printLine("*");

        ConsoleHandler::printLine("*------------------------------*");
    }

    void printHeader(const std::string &string)
    {
        ConsoleHandler::printLine("*** " + string + " ***");
    }

}