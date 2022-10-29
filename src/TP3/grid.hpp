#pragma once

#include "cell.hpp"
#include "symbol.hpp"
#include <vector>

class Grid
{
public:
    /**
     * @brief Construct a new Grid object
     *
     * @param size
     */
    Grid(unsigned int x, unsigned int y);

    /**
     * @brief Get grid X size
     *
     * @return unsigned int
     */
    inline unsigned int getXSize() const { this->xSize; };

    /**
     * @brief Get grid Y size
     *
     * @return unsigned int
     */
    inline unsigned int getYSize() const { this->ySize; };

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
    Symbol getCell(Cell cell) const;

    /**
     * @brief Get all the free cells remainings
     *
     * @return std::vector<Cell>
     */
    std::vector<Cell> getFreeCells() const;

    /**
     * @brief Get the Max Consecutive Symbols object
     *
     * @param symbol
     * @return unsigned int
     */
    unsigned int getMaxConsecutiveSymbols(Symbol symbol) const;

    /**
     * @brief Display grid in the console
     *
     */
    void displayGrid() const;

private:
    unsigned int xSize;
    unsigned int ySize;
    std::vector<std::vector<Symbol>> grid;
};