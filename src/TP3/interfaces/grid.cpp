#include "grid.hpp"

template class Grid<unsigned int>;

template <typename T>
T Grid<T>::getElementAt(const Position &position) const
{
    if (!this->isPositionInBounds(position))
    {
        throw OutOfBoundsException();
    }

    return this->grid.at(position.y).at(position.x);
}

template <typename T>
bool Grid<T>::isPositionEmpty(const Position &position) const
{
    return !this->getElementAt(position);
}

template <typename T>
bool Grid<T>::isPositionInBounds(const Position &position) const
{
    return (position.x >= 0 && position.x < this->xSize) && (position.y >= 0 && position.y < this->ySize);
}

template <typename T>
bool Grid<T>::isFull() const
{
    return getEmptyPositions().size() == 0;
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
bool Grid<T>::replaceAt(const Position &position, const T &element)
{
    try
    {
        if (!this->isPositionInBounds(position))
        {
            throw OutOfBoundsException();
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
std::vector<Position> Grid<T>::getEmptyPositions() const
{
    std::vector<Position> freePositions;

    for (int row = 0; row < this->ySize; row++)
    {
        for (int col = 0; col < this->xSize; col++)
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
void Grid<T>::display() const
{

    ConsoleHandler::print("\n   ");
    for (int col = 0; col < this->getXSize(); col++)
    {
        ConsoleHandler::print(std::to_string(col + 1) + " ");
    }

    ConsoleHandler::print("\n  ┌");
    for (int col = 0; col < (this->getXSize() * 2) - 1; col++)
    {
        if (col % 2 == 0)
        {
            ConsoleHandler::print("─");
        }
        else
        {
            ConsoleHandler::print("┬");
        }
    }
    ConsoleHandler::printLine("┐");

    for (int row = 0; row < this->getYSize(); row++)
    {

        ConsoleHandler::print(std::to_string(row + 1) + " │");

        for (int col = 0; col < this->getXSize(); col++)
        {
            std::string characterAsString(1, Player::getPlayerChar(this->getElementAt({x : col, y : row})));
            ConsoleHandler::print(characterAsString);

            if (col < this->getXSize() - 1)
            {
                ConsoleHandler::print("│");
            }
        }
        ConsoleHandler::printLine("│");
    }

    ConsoleHandler::print("  └");
    for (int col = 0; col < (this->getXSize() * 2) - 1; col++)
    {
        if (col % 2 == 0)
        {
            ConsoleHandler::print("─");
        }
        else
        {
            ConsoleHandler::print("┴");
        }
    }
    ConsoleHandler::printLine("┘");
}