#pragma once

#include <iostream>
#include <string>

namespace ConsoleHandler
{
    std::string getInput();
    void print(const std::string &output);
    void printLine(const std::string &output);
    int readInt();
    void printTitle(const std::string &string);
    void printHeader(const std::string &string);
};