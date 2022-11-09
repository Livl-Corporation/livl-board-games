#pragma once

#include <exception>

class ColumnFullException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Cette colonne est pleine !";
    }
};