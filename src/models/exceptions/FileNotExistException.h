#pragma once

#include <exception>

class FileNotExistException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "The provided file does not exist !";
    }
};