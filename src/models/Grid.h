#ifndef LIVL_GRID_H
#define LIVL_GRID_H

#include <vector>
#include <memory>

#include "Position.h"
#include "models/exceptions/OutOfBoundsException.h"
#include "models/exceptions/OccupiedPositionException.h"

typedef unsigned int GridSize;

template <typename T> requires std::is_base_of<Serializable, T>::value
class Grid: Serializable {

public:

    Grid(GridSize rows, GridSize cols, std::shared_ptr<T> &defaultValue)
    : colCount(cols), rowCount(rows), grid(rows, std::vector<std::shared_ptr<T>>(cols, defaultValue)) {
        this->defaultValue = defaultValue;
    }

    [[nodiscard]] inline GridSize getColCount() const { return this->colCount; };

    [[nodiscard]] inline GridSize getRowCount() const { return this->rowCount; };

    [[nodiscard]] bool isPositionEmpty(const Position &position) const;

    [[nodiscard]] bool isPositionInBounds(const Position &position) const;

    [[nodiscard]] bool isPositionOnBorder(const Position &position) const;

    [[nodiscard]] bool isFull() const;

    void place(const Position &position, const std::shared_ptr<T> &element);

    bool replaceAt(const Position &position, const std::shared_ptr<T> &element);

    std::shared_ptr<T> getElementAt(const Position &position) const;

    [[nodiscard]] std::vector<Position> getEmptyPositions() const;

    void serialize(std::ostream &stream) override;

    void deserialize(std::istream &stream) override;

private:
    GridSize colCount;
    GridSize rowCount;
    std::vector<std::vector<std::shared_ptr<T>>> grid;
    std::shared_ptr<T> defaultValue;
};

#endif //LIVL_GRID_H