#pragma once

#include <string>
#include <random>
#include <iostream>

/**
 * @brief Get the Player Char object
 *
 * @param playerId
 * @return char
 */
char getPlayerChar(int playerId);

/**
 * @brief Get a random int between min & max
 *
 * @param max
 * @return unsigned int
 */
int randomInt(int min, int max);

/**
 * @brief Read an integer from user
 *
 * @return int
 */
int readInt();

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