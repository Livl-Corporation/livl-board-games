#pragma once

#include "models/cell.hpp"
#include "models/player.hpp"

#include "shared/functions.hpp"
#include "shared/exceptions/out-of-bounds-exception.hpp"
#include "shared/exceptions/occupied-cell-exception.hpp"
#include "shared/exceptions/column-full-exception.hpp"

#include <vector>
#include <iostream>

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
    inline unsigned int getXSize() const { return this->xSize; };

    /**
     * @brief Get grid Y size
     *
     * @return unsigned int
     */
    inline unsigned int getYSize() const { return this->ySize; };

    /**
     * @brief Return true if requested cell is empty;
     *
     * @param cell
     * @return true
     * @return false
     */
    bool isCellEmpty(const Cell &cell) const;

    /**
     * @brief Return true if requested cell is in grid bounds
     *
     * @param cell
     * @return true
     * @return false
     */
    bool isCellInBounds(const Cell &cell) const;

    /**
     * @brief Return true if there is no free cells left
     *
     * @return true
     * @return false
     */
    bool isGridFull() const;

    /**
     * @brief Place id on cell
     *
     * @param cell
     * @param id
     * @return true
     * @return false
     */
    bool place(const Cell &cell, const unsigned int id);

    /**
     * @brief Get the symbol placed on provided cell
     *
     * @param cell
     * @return Symbol
     */
    int getCell(const Cell &cell) const;

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

    /**
     * @brief Get the first row available in a given col
     *
     * @param col
     * @return unsigned int
     */
    unsigned int firstRowAvailableInCol(const unsigned int col) const;

private:
    unsigned int xSize;
    unsigned int ySize;
    std::vector<std::vector<int>> grid;
};