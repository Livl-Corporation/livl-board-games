#include "triangle.hpp"
#include <array>
#include "functions.hpp"
#include <iostream>

inline float Triangle::base() const
{
    std::array<float, 3> lengths = this->getLengths();
    float base = 0.0;
    for (int i = 0; i < 3; i++)
    {
        if (lengths[i] > base)
        {
            base = lengths[1];
        }
    }
    return base;
}

inline float Triangle::height() const
{
    return this->surface() / (this->base() / 2);
}

inline float Triangle::surface() const
{
    std::array<float, 3> lengths = this->getLengths();
    float s = (lengths[0] + lengths[1] + lengths[2]) / 2.0;
    return std::sqrt(s * (s - lengths[0]) * (s - lengths[1]) * (s - lengths[2]));
}

inline std::array<float, 3> Triangle::getLengths() const
{
    float distance1 = distanceBetweenPoints(this->getPoint1(), this->getPoint2());
    float distance2 = distanceBetweenPoints(this->getPoint2(), this->getPoint3());
    float distance3 = distanceBetweenPoints(this->getPoint3(), this->getPoint1());
    return {distance1, distance2, distance3};
}

inline bool Triangle::isIsoceles() const
{
    std::array<float, 3> lengths = this->getLengths();
    return (lengths[0] == lengths[1] ||
            lengths[1] == lengths[2] ||
            lengths[2] == lengths[0]);
}

inline bool Triangle::isRectangle() const
{
    std::array<float, 3> lengths = this->getLengths();
    return (
        std::pow(lengths[0], 2) == (std::pow(lengths[1], 2) + std::pow(lengths[2], 2)) || std::pow(lengths[1], 2) == (std::pow(lengths[0], 2) + std::pow(lengths[2], 2)) || std::pow(lengths[2], 2) == (std::pow(lengths[1], 2) + std::pow(lengths[0], 2)));
}

inline bool Triangle::isEquilateral() const
{
    std::array<float, 3> lengths = this->getLengths();
    return (lengths[0] == lengths[1] && lengths[1] == lengths[2]);
}

void Triangle::afficher() const
{
    std::array<float, 3> lengths = this->getLengths();
    std::cout << "--- Triangle ---" << std::endl;
    std::cout << "Point 1 : (" << this->getPoint1().x << ", " << this->getPoint1().y << ")" << std::endl;
    std::cout << "Point 2 : (" << this->getPoint2().x << ", " << this->getPoint2().y << ")" << std::endl;
    std::cout << "Point 3 : (" << this->getPoint3().x << ", " << this->getPoint3().y << ")" << std::endl;
    std::cout << "Longueur 1 : " << lengths[0] << std::endl;
    std::cout << "Longueur 2 : " << lengths[1] << std::endl;
    std::cout << "Longueur 3 : " << lengths[2] << std::endl;
    std::cout << "Base : " << this->base() << std::endl;
    std::cout << "Hauteur : " << this->height() << std::endl;
    std::cout << "Surface : " << this->surface() << std::endl;
    std::cout << "Isocèle : " << this->isIsoceles() << std::endl;
    std::cout << "Triangle rectangle : " << this->isRectangle() << std::endl;
    std::cout << "Equilateral : " << this->isEquilateral() << std::endl;
}