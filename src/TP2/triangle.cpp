#include "triangle.hpp"
#include <array>
#include "functions.hpp"

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
}

inline bool Triangle::isEquilateral() const
{
    std::array<float, 3> lengths = this->getLengths();
    return (lengths[0] == lengths[1] && lengths[1] == lengths[2]);
}