#ifndef LIVL_GRID_H
#define LIVL_GRID_H

#include <vector>
#include "Position.h"
#include "models/exceptions/OutOfBoundsException.h"
#include "models/exceptions/OccupiedPositionException.h"

typedef unsigned int GridSize;

template <typename T>
class Grid {

public:

    Grid(GridSize cols, GridSize rows, T &defaultValue)
    : colCount(cols), rowCount(rows), grid(rows, std::vector<T>(cols, defaultValue)) {
        this->defaultValue = defaultValue;
    }

    [[nodiscard]] inline GridSize getColCount() const { return this->colCount; };

    [[nodiscard]] inline GridSize getRowCount() const { return this->rowCount; };

    [[nodiscard]] bool isPositionEmpty(const Position &position) const;

    [[nodiscard]] bool isPositionInBounds(const Position &position) const;

    [[nodiscard]] bool isPositionOnBorder(const Position &position) const;

    [[nodiscard]] bool isFull() const;

    void place(const Position &position, const T &element);

    bool replaceAt(const Position &position, const T &element);

    T getElementAt(const Position &position) const;

    [[nodiscard]] std::vector<Position> getEmptyPositions() const;

private:
    GridSize colCount;
    GridSize rowCount;
    std::vector<std::vector<T>> grid;
    T defaultValue;
};

#endif //LIVL_GRID_H