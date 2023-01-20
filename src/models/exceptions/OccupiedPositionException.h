#pragma once

#include <exception>

class OccupiedPositionException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "The requested position is already occupied !";
    }
};