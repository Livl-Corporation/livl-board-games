#include "Grid.h"

template <typename T> requires std::is_base_of<Serializable, T>::value
T Grid<T>::getElementAt(const Position &position) const
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    return this->grid.at(position.y).at(position.x);
}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isPositionEmpty(const Position &position) const
{
    return this->getElementAt(position) == defaultValue;
}


template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isPositionInBounds(const Position &position) const
{
    return (position.x >= 0 && position.x < this->xSize) && (position.y >= 0 && position.y < this->ySize);
}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isPositionOnBorder(const Position &position) const
{
    return (position.x == 0 || position.x == this->xSize - 1) || (position.y == 0 || position.y == this->ySize - 1);
}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isFull() const
{
    return getEmptyPositions().size() == 0;
}

template <typename T> requires std::is_base_of<Serializable, T>::value
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

    this->grid[position.y][position.x] = element;

}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::replaceAt(const Position &position, const T &element)
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    this->grid[position.y][position.x] = element;

    return true;
}

template <typename T> requires std::is_base_of<Serializable, T>::value
std::vector<Position> Grid<T>::getEmptyPositions() const
{
    std::vector<Position> freePositions;

    for (int row = 0; row < this->ySize; row++)
    {
        for (int col = 0; col < this->xSize; col++)
        {
            Position position(col, row);
            if (this->isPositionEmpty(position))
            {
                freePositions.push_back(position);
            }
        }
    }

    return freePositions;
}

template <typename T> requires std::is_base_of<Serializable, T>::value
void Grid<T>::serialize(std::ostream &stream) {
    defaultValue.serialize(stream);

    stream << xSize << std::endl;
    stream << ySize << std::endl;

    for (int row = 0; row < this->ySize; row++)
    {
        for (int col = 0; col < this->xSize; col++)
        {
            this->grid[row][col].serialize(stream);
        }
    }

}

template <typename T> requires std::is_base_of<Serializable, T>::value
void Grid<T>::deserialize(std::istream &stream) {

}