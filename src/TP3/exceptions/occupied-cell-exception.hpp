#pragma once

#include <exception>

class OccupiedCellException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "La cellule demandée est déjà occupée !";
    }
};