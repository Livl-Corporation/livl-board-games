#ifndef LIVL_GRID_H
#define LIVL_GRID_H

#include <vector>
#include <memory>
#include <algorithm>

#include "Position.h"
#include "models/exceptions/OutOfBoundsException.h"
#include "models/exceptions/OccupiedPositionException.h"

typedef unsigned int GridSize;

template <typename T> requires std::is_base_of<Serializable, T>::value
class Grid: Serializable {

public:

    Grid(GridSize rows, GridSize cols, std::shared_ptr<T> &defaultValue)
    : colCount(cols), rowCount(rows) {
        this->defaultValue = defaultValue;

        // Create a new pointer with value = default value for each cell
        for (int row = 0; row < this->rowCount; row++)
        {
            std::vector<std::shared_ptr<T>> rowVector;
            for (int col = 0; col < this->colCount; col++)
            {
                rowVector.push_back(std::make_shared<T>(*defaultValue));
            }
            this->grid.push_back(rowVector);
        }

    }

    explicit Grid(std::istream &stream) { this->deserialize(stream); }

    [[nodiscard]] inline GridSize getColCount() const { return this->colCount; };

    [[nodiscard]] inline GridSize getRowCount() const { return this->rowCount; };

    [[nodiscard]] bool isPositionEmpty(const Position &position) const;

    [[nodiscard]] bool isPositionInBounds(const Position &position) const;

    [[nodiscard]] bool isPositionOnBorder(const Position &position) const;

    [[nodiscard]] bool isFull() const;

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