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
    inline int getXSize() const { return this->xSize; };

    inline int getYSize() const { return this->ySize; };

    bool isPositionEmpty(const Position &position) const;

    bool isPositionInBounds(const Position &position) const;

    bool isGridFull() const;

    bool place(const Position &position, const T &element);
    bool change(const Position &position, const T &element);

    T getElementAt(const Position &position) const;
    std::vector<Position> getEmptyPositions() const;

    void displayGrid() const;
protected:
    Grid(const unsigned int x, const unsigned int y, const T &defaultValue)
        : xSize(x), ySize(y), grid(y, std::vector<T>(x, defaultValue))
    {
    }

private:
    unsigned int xSize;
    unsigned int ySize;
    std::vector<std::vector<T>> grid;
};