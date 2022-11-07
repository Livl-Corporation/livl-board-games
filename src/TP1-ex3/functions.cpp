#include <iostream>
#include <cctype>
#include <cstring>
#include "functions.hpp"

void toUpper(std::string &string)
{
    for (int i = 0; i < string.length(); i++)
    {
        string[i] = toupper(string[i]);
    }
}

void capitalize(std::string &string)
{
    string[0] = toupper(string[0]);
}