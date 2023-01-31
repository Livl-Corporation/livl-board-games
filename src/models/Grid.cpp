#include "Grid.h"

template <typename T> requires std::is_base_of<Serializable, T>::value
std::shared_ptr<T> Grid<T>::getElementAt(const Position &position) const
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    return this->grid.at(position.row).at(position.col);
}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isPositionEmpty(const Position &position) const
{
    return (*this->getElementAt(position)) == *defaultValue;
}


template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isPositionInBounds(const Position &position) const
{
    return (position.col >= 0 && position.col < this->colCount) && (position.row >= 0 && position.row < this->rowCount);
}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isPositionOnBorder(const Position &position) const
{
    return (position.col == 0 || position.col == this->colCount - 1) || (position.row == 0 || position.row == this->rowCount - 1);
}

template <typename T> requires std::is_base_of<Serializable, T>::value
bool Grid<T>::isFull() const
{
    return getEmptyPositions().size() == 0;
}

template <typename T> requires std::is_base_of<Serializable, T>::value
std::vector<Position> Grid<T>::getEmptyPositions() const
{
    std::vector<Position> freePositions;

    for (int row = 0; row < this->rowCount; row++)
    {
        for (int col = 0; col < this->colCount; col++)
        {
            Position position(row, col);
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
    defaultValue->serialize(stream);

    stream << this->colCount << std::endl;
    stream << this->rowCount << std::endl;

    for (int row = 0; row < this->rowCount; row++)
    {
        for (int col = 0; col < this->colCount; col++)
        {
            this->grid[row][col]->serialize(stream);
        }
    }

}

template <typename T> requires std::is_base_of<Serializable, T>::value
void Grid<T>::deserialize(std::istream &stream) {

}