#include "Position.h"

void Position::serialize(std::ostream &stream)
{
    stream << this->row << std::endl;
    stream << this->col << std::endl;
}

void Position::deserialize(std::istream &stream)
{
    stream >> this->row;
    stream >> this->col;
}

