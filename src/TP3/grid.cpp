#include "grid.hpp"

template class Grid<unsigned int>;

template <typename T>
T Grid<T>::getElementAt(const Position &position) const
{
    return this->grid.at(position.y).at(position.x);
}

template <typename T>
bool Grid<T>::isPositionEmpty(const Position &position) const
{
    if (!this->isPositionInBounds(position))
    {
        throw new OutOfBoundsException();
    }

    return this->getElementAt(position) == NO_PLAYER;
}

template <typename T>
bool Grid<T>::isPositionInBounds(const Position &position) const
{
    return (position.x >= 0 && position.x < this->xSize) && (position.y >= 0 && position.y < this->ySize);
}

template <typename T>
bool Grid<T>::isGridFull() const
{
    return getFreePositions().size() == 0;
}

template <typename T>
bool Grid<T>::place(const Position &position, const T &element)
{
    try
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

        return true;
    }
    catch (const std::exception &e)
    {
        ConsoleHandler::printLine("\n" + std::string(e.what()) + "\n");
        return false;
    }
}

template <typename T>
std::vector<Position> Grid<T>::getFreePositions() const
{
    std::vector<Position> freePositions;

    for (unsigned int row = 0; row < this->ySize; row++)
    {
        for (unsigned int col = 0; col < this->xSize; col++)
        {
            Position position = {x : col, y : row};
            if (this->isPositionEmpty(position))
            {
                freePositions.push_back(position);
            }
        }
    }

    return freePositions;
}

template <typename T>
void Grid<T>::displayGrid() const
{
    ConsoleHandler::print("\n");

    for (unsigned int row = 0; row < this->getYSize(); row++)
    {
        for (unsigned int col = 0; col < this->getXSize(); col++)
        {
            std::string characterAsString(1, Player::getPlayerChar(this->getElementAt({x : col, y : row})));
            ConsoleHandler::print(characterAsString);

            if (col < this->getXSize() - 1)
            {
                ConsoleHandler::print("|");
            }
        }
        ConsoleHandler::printLine("");
    }
    ConsoleHandler::printLine("");
}