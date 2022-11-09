#pragma once

#include "cell.hpp"
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
    bool place(Cell cell, int id);

    /**
     * @brief Get the symbol placed on provided cell
     *
     * @param cell
     * @return Symbol
     */
    int getCell(Cell cell) const;

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
    unsigned int getMaxConsecutiveIds(int id) const;

    /**
     * @brief Display grid in the console
     *
     */
    void displayGrid() const;

private:
    unsigned int xSize;
    unsigned int ySize;
    std::vector<std::vector<int>> grid;
};