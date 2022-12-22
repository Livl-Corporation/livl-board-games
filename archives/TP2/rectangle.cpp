#include "rectangle.hpp"
#include <iostream>

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

void Rectangle::afficher() const
{
    std::cout << "--- Triangle ---" << std::endl;
    std::cout << "Hauteur : " << this->getHeight() << std::endl;
    std::cout << "Largeur : " << this->getWidth() << std::endl;
    std::cout << "Origine : (" << this->getOrigin().x << ", " << this->getOrigin().y << ")" << std::endl;
    std::cout << "Périmètre : " << this->getPerimeter() << std::endl;
    std::cout << "Surface : " << this->getSurface() << std::endl;
}
