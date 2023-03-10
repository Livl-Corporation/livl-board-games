#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

namespace ConsoleHandler
{
    std::string getInput();
    void printLine(const std::string &output);
    void print(const std::string &output);
    int readInt();
    std::vector<int> readValues(unsigned int numValues);
    void printTitle(const std::string &string);
    void printHeader(const std::string &string);
}