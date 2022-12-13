#pragma once

#include <iostream>
#include <string>

namespace ConsoleHandler
{
    std::string getInput();
    void printOutput(const std::string &output);
    void printOutputWithoutNewLine(const std::string &output);
    int readInt();
    void printTitle(const std::string &string);
    void printHeader(const std::string &string);
};