#pragma once

#include "models/position.hpp"
#include "models/player.hpp"

#include "shared/consoleHandler.hpp"
#include "shared/exceptions/out-of-bounds-exception.hpp"
#include "shared/exceptions/occupied-position-exception.hpp"
#include "shared/exceptions/column-full-exception.hpp"

#include <vector>
#include <string>

template <typename T>
class Grid
{
public:
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
     * @brief Return true if requested position is empty;
     *
     * @param position
     * @return true
     * @return false
     */
    bool isPositionEmpty(const Position &position) const;

    /**
     * @brief Return true if requested position is in grid bounds
     *
     * @param position
     * @return true
     * @return false
     */
    bool isPositionInBounds(const Position &position) const;

    /**
     * @brief Return true if there is no free positions left
     *
     * @return true
     * @return false
     */
    bool isGridFull() const;

    /**
     * @brief Place id on position
     *
     * @param position
     * @param id
     * @return true
     * @return false
     */
    bool place(const Position &position, const T &element);

    /**
     * @brief Get the symbol placed on provided position
     *
     * @param position
     * @return Symbol
     */
    T getElementAt(const Position &position) const;

    /**
     * @brief Get all the free positions remainings
     *
     * @return std::vector<Position>
     */
    std::vector<Position> getFreePositions() const;

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
    // unsigned int firstRowAvailableInCol(const unsigned int col) const;

protected:
    /**
     * @brief Construct a new Grid object
     *
     * @param size
     */
    Grid(const unsigned int x, const unsigned int y, const T &defaultValue)
        : xSize(x), ySize(y), grid(y, std::vector<T>(x, defaultValue))
    {
    }

private:
    unsigned int xSize;
    unsigned int ySize;
    std::vector<std::vector<T>> grid;
};