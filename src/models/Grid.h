#pragma once

#include <vector>
#include "Position.h"
#include "models/exceptions/OutOfBoundsException.h"
#include "models/exceptions/OccupiedPositionException.h"
//#include "Subject.h"

typedef unsigned int GridSize;

template <typename T>
class Grid {

public:

    Grid(GridSize x, GridSize y, T &defaultValue)
    : xSize(x), ySize(y), grid(y, std::vector<T>(x, defaultValue)) {}

    [[nodiscard]] inline GridSize getXSize() const { return this->xSize; };

    [[nodiscard]] inline GridSize getYSize() const { return this->ySize; };

    [[nodiscard]] bool isPositionEmpty(const Position &position) const;

    [[nodiscard]] bool isPositionInBounds(const Position &position) const;

    [[nodiscard]] bool isPositionOnBorder(const Position &position) const;

    [[nodiscard]] bool isFull() const;

    bool place(const Position &position, const T &element);

    bool replaceAt(const Position &position, const T &element);

    T getElementAt(const Position &position) const;

    [[nodiscard]] std::vector<Position> getEmptyPositions() const;

private:
    GridSize xSize;
    GridSize ySize;
    std::vector<std::vector<T>> grid;
};