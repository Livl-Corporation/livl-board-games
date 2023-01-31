#include "Position.h"

void Position::serialize(std::ostream &stream)
{
    stream << this->x << std::endl;
    stream << this->y << std::endl;
}

void Position::deserialize(std::istream &stream)
{
    stream >> this->x;
    stream >> this->y;
}

