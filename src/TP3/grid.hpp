#pragma once

#include "cell.hpp"
#include "symbol.hpp"
#include <vector>
#include <optional>

class Grid
{
public:
    /**
     * @brief Construct a new Grid object
     *
     * @param size
     */
    Grid(unsigned int size) { this->size = size; };

    /**
     * @brief Get the Size object
     *
     * @return unsigned int
     */
    inline unsigned int getSize() const { this->size; };

    /**
     * @brief Return true if requested cell is empty;
     *
     * @param cell
     * @return true
     * @return false
     */
    bool isCellEmpty(Cell cell) const;

    /**
     * @brief Return true if requested cell is in grid bounds
     *
     * @param cell
     * @return true
     * @return false
     */
    bool isCellInBounds(Cell cell) const;

    /**
     * @brief Place provided symbol on requested cell
     *
     * @param cell
     * @param Symbol
     * @return true
     * @return false
     */
    bool placeSymbol(Cell cell, Symbol Symbol);

    /**
     * @brief Get the symbol placed on provided cell
     *
     * @param cell
     * @return Symbol
     */
    std::optional<Symbol> getCell(Cell cell) const;

    /**
     * @brief Get all the free cells remainings
     *
     * @return std::vector<Cell>
     */
    std::vector<Cell> getFreeCells() const;

    /**
     * @brief Display grid in the console
     *
     */
    void displayGrid() const;

private:
    unsigned int size;
    std::vector<std::vector<std::optional<Symbol>>> grid;
};