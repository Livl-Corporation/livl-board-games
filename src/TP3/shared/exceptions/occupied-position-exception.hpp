#pragma once

#include <exception>

class OccupiedPositionException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "The requested position is already occupied !";
    }
};