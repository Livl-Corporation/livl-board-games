#pragma once

#include <exception>

class OutOfBoundsException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "The requested position is off the grid !";
    }
};