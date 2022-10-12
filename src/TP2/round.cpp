#include "round.hpp"
#include <cmath>

double Round::distanceFromOrigin(const Point &point) const
{
    return std::sqrt(std::pow(point.x - this->origin.x, 2) - std::pow(point.y - this->origin.y, 2));
}

bool Round::isOnCircle(const Point &point) const
{
    return distanceFromOrigin(point) == diameter;
}

bool Round::isInCircle(const Point &point) const
{
    return distanceFromOrigin(point) < diameter;
}