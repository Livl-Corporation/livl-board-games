#include "Grid.h"

template <typename T>
T Grid<T>::getElementAt(const Position &position) const
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    return this->grid.at(position.row).at(position.col);
}

template <typename T>
bool Grid<T>::isPositionEmpty(const Position &position) const
{
    return this->getElementAt(position) == defaultValue;
}


template <typename T>
bool Grid<T>::isPositionInBounds(const Position &position) const
{
    return (position.col >= 0 && position.col < this->colCount) && (position.row >= 0 && position.row < this->rowCount);
}

template <typename T>
bool Grid<T>::isPositionOnBorder(const Position &position) const
{
    return (position.col == 0 || position.col == this->colCount - 1) || (position.row == 0 || position.row == this->rowCount - 1);
}

template <typename T>
bool Grid<T>::isFull() const
{
    return getEmptyPositions().size() == 0;
}

template <typename T>
void Grid<T>::place(const Position &position, const T &element)
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    if (!this->isPositionEmpty(position))
    {
        throw OccupiedPositionException();
    }

    this->grid[position.row][position.col] = element;

}

template <typename T>
bool Grid<T>::replaceAt(const Position &position, const T &element)
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    this->grid[position.row][position.col] = element;

    return true;
}

template <typename T>
std::vector<Position> Grid<T>::getEmptyPositions() const
{
    std::vector<Position> freePositions;

    for (int row = 0; row < this->rowCount; row++)
    {
        for (int col = 0; col < this->colCount; col++)
        {
            Position position = {row, col};
            if (this->isPositionEmpty(position))
            {
                freePositions.push_back(position);
            }
        }
    }

    return freePositions;
}