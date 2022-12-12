#pragma once

#include <iostream>
#include <string>

class ConsoleHandler
{
public:
    static std::string getInput();
    static void printOutput(const std::string& output);
    static void printOutputWithoutNewLine(const std::string& output);
};