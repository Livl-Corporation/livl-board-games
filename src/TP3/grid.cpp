#include "grid.hpp"

int Grid::getPosition(const Position &position) const
{
    return this->grid.at(position.y).at(position.x);
}

bool Grid::isPositionEmpty(const Position &position) const
{
    if (!this->isPositionInBounds(position))
    {
        throw new OutOfBoundsException();
    }

    return this->getPosition(position) == NO_PLAYER;
}

bool Grid::isPositionInBounds(const Position &position) const
{
    return (position.x >= 0 && position.x < this->xSize) && (position.y >= 0 && position.y < this->ySize);
}

bool Grid::isGridFull() const
{
    return getFreePositions().size() == 0;
}

bool Grid::place(const Position &position, const unsigned int id)
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

        this->grid[position.y][position.x] = id;

        return true;
    }
    catch (const std::exception &e)
    {
        ConsoleHandler::printOutput("\n" + std::string(e.what()) + "\n");
        return false;
    }
}

std::vector<Position> Grid::getFreePositions() const
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

void Grid::displayGrid() const
{
    ConsoleHandler::printOutputWithoutNewLine("\n");

    for (unsigned int row = 0; row < this->getYSize(); row++)
    {
        for (unsigned int col = 0; col < this->getXSize(); col++)
        {
    	    std::string characterAsString(1, Player::getPlayerChar(this->getPosition({x : col, y : row})));
            ConsoleHandler::printOutputWithoutNewLine(characterAsString);            
            
            if (col < this->getXSize() - 1)
            {
                ConsoleHandler::printOutputWithoutNewLine("|");
            }        
        }
        ConsoleHandler::printOutputWithoutNewLine("\n");
    }
    ConsoleHandler::printOutputWithoutNewLine("\n");
}

unsigned int Grid::firstRowAvailableInCol(unsigned int col) const
{
    Position position{x : col, y : (this->getYSize() - 1)};

    while (!this->isPositionEmpty(position))
    {

        if (position.y == 0)
        {
            // If there is no row available in this col, throw an exception & exit function
            throw ColumnFullException();
        }
        else
        {
            position.y--;
        }
    }

    return position.y;
}