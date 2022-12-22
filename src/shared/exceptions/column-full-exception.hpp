#pragma once

#include <exception>

class ColumnFullException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "This column is full !";
    }
};