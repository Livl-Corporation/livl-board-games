#pragma once

#include <exception>

class UnimplementedPlayMode : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "The requested play mode is not implemented !";
    }
};