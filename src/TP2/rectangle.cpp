#include "rectangle.hpp"

void Rectangle::setOrigin(const Point &point)
{
    this->origin = point;
}

inline float Rectangle::getPerimeter() const
{
    return this->height * 2 + this->width * 2;
}

inline float Rectangle::getSurface() const
{
    return this->height * this->width;
}

bool Rectangle::hasBiggerPerimeter(const Rectangle &rectangle) const
{
    return this->getPerimeter() > rectangle.getPerimeter();
}

bool Rectangle::hasBiggerSurface(const Rectangle &rectangle) const
{
    return this->getSurface() > rectangle.getSurface();
}