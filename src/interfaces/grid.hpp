#pragma once

#include "../models/position.hpp"
#include "../models/player.hpp"

#include "../cli/consoleHandler.hpp"
#include "../shared/exceptions/out-of-bounds-exception.hpp"
#include "../shared/exceptions/occupied-position-exception.hpp"
#include "../shared/exceptions/column-full-exception.hpp"

#include <vector>
#include <string>

template <typename T>
class Grid
{
public:
    [[nodiscard]] inline int getXSize() const { return this->xSize; };

    [[nodiscard]] inline int getYSize() const { return this->ySize; };

    [[nodiscard]] bool isPositionEmpty(const Position &position) const;

    [[nodiscard]] bool isPositionInBounds(const Position &position) const;

    [[nodiscard]] bool isFull() const;

    bool place(const Position &position, const T &element);

    bool replaceAt(const Position &position, const T &element);

    T getElementAt(const Position &position) const;

    [[nodiscard]] std::vector<Position> getEmptyPositions() const;

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