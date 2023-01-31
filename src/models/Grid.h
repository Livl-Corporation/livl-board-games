#ifndef LIVL_GRID_H
#define LIVL_GRID_H

#include <vector>
#include "Position.h"
#include "models/exceptions/OutOfBoundsException.h"
#include "models/exceptions/OccupiedPositionException.h"

typedef unsigned int GridSize;

template <typename T> requires std::is_base_of<Serializable, T>::value
class Grid: Serializable {

public:

    Grid(GridSize x, GridSize y, T &defaultValue)
    : xSize(x), ySize(y), grid(y, std::vector<T>(x, defaultValue)) {
        this->defaultValue = defaultValue;
    }

    [[nodiscard]] inline GridSize getXSize() const { return this->xSize; };

    [[nodiscard]] inline GridSize getYSize() const { return this->ySize; };

    [[nodiscard]] bool isPositionEmpty(const Position &position) const;

    [[nodiscard]] bool isPositionInBounds(const Position &position) const;

    [[nodiscard]] bool isPositionOnBorder(const Position &position) const;

    [[nodiscard]] bool isFull() const;

    void place(const Position &position, const T &element);

    bool replaceAt(const Position &position, const T &element);

    T getElementAt(const Position &position) const;

    [[nodiscard]] std::vector<Position> getEmptyPositions() const;

    void serialize(std::ostream &stream) override;

    void deserialize(std::istream &stream) override;

private:
    GridSize xSize;
    GridSize ySize;
    std::vector<std::vector<T>> grid;
    T defaultValue;
};

#endif //LIVL_GRID_H