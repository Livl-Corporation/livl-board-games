#pragma once

#include <exception>

class OutOfBoundsException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "The requested position is off the grid !";
    }
};