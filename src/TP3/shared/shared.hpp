#pragma once

#include <string>
#include <random>
#include "consoleHandler.hpp"

namespace Shared
{
    /**
     * @brief Get a random int between min & max
     *
     * @param max
     * @return unsigned int
     */
    int randomInt(int min, int max);

    /**
     * @brief Print a title in the console
     *
     * @param string
     */
    void printTitle(const std::string &string);

    /**
     * @brief Print a header in the console
     *
     * @param string
     */
    void printHeader(const std::string &string);
}