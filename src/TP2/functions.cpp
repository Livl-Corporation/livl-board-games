#include "functions.hpp"

float distanceBetweenPoints(Point point1, Point point2)
{
    return std::sqrt(std::pow(point1.x - point2.x, 2) - std::pow(point1.y - point2.y, 2));
}