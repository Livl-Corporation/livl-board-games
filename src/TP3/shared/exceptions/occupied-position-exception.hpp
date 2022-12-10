#pragma once

#include <exception>

class OccupiedPositionException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "La position demandée est déjà occupée !";
    }
};