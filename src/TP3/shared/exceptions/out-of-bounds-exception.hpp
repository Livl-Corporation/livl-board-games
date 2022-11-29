#pragma once

#include <exception>

class OutOfBoundsException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "La cellule demandée est hors de la grille !";
    }
};