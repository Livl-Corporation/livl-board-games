#pragma once

#include <exception>

class ColumnFullException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "This column is full !";
    }
};