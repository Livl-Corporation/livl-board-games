#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <array>
#include "point.hpp"

class Triangle
{

public:
    /**
     * @brief Get the Point1 object
     *
     * @return Point
     */
    inline Point getPoint1() const { return point1; }

    /**
     * @brief Get the Point2 object
     *
     * @return Point
     */
    inline Point getPoint2() const { return point2; }

    /**
     * @brief Get the Point3 object
     *
     * @return Point
     */
    inline Point getPoint3() const { return point3; }

    /**
     * @brief Set the Point1 object
     *
     * @param point
     */
    inline void setPoint1(const Point &point) { this->point1 = point; }

    /**
     * @brief Set the Point2 object
     *
     * @param point
     */
    inline void setPoint2(const Point &point) { this->point2 = point; }

    /**
     * @brief Set the Point3 object
     *
     * @param point
     */
    inline void setPoint3(const Point &point) { this->point3 = point; }

    /**
     * @brief Get triagle base width
     *
     * @return float
     */
    inline float base() const;

    /**
     * @brief Get triangle height
     *
     * @return float
     */
    inline float height() const;

    /**
     * @brief Get triangle suface
     *
     * @return float
     */
    inline float surface() const;

    /**
     * @brief Get the Lengths object
     *
     * @return std::array<float, 3>
     */
    inline std::array<float, 3> getLengths() const;

    /**
     * @brief Return true if triangle is isoceles
     *
     * @return bool
     */
    inline bool isIsoceles() const;

    /**
     * @brief Return true if triangle is rectangle
     *
     * @return bool
     */
    inline bool isRectangle() const;

    /**
     * @brief Return true if triangle is equilateral
     *
     * @return bool
     */
    inline bool isEquilateral() const;

private:
    Point point1, point2, point3;
};

#endif