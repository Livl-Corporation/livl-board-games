#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <QLabel>

namespace ConsoleHandler
{
    std::string getInput();
    void printLineLabel(QLabel* label, const std::string& output);
    void printLine(const std::string &output);
    void print(const std::string &output);
    int readInt();
    std::vector<int> readValues(int numValues);
    void printTitle(const std::string &string);
    void printHeader(const std::string &string);
}