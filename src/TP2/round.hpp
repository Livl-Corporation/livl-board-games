#ifndef ROUND_HPP
#define ROUND_HPP

#include "point.hpp"

class Round
{

public:
    /**
     * @brief Get the Origin object
     *
     * @return Point
     */
    inline Point getOrigin() const { return origin; }

    /**
     * @brief Get the Diameter object
     *
     * @return int
     */
    inline int getDiameter() const { return diameter; }

    /**
     * @brief Set the Origin object
     *
     * @param origin
     */
    void setOrigin(const Point &origin) { this->origin = origin; }

    /**
     * @brief Set the Diameter object
     *
     * @param diameter
     */
    inline void setDiameter(int diameter) { this->diameter = diameter; }

    /**
     * @brief Get round perimeter
     *
     * @return float
     */
    inline float perimeter() const;

    /**
     * @brief Get round surface
     *
     * @return float
     */
    inline float surface() const;

    /**
     * @brief Return true if given point is on circle
     *
     * @param point
     * @return true
     * @return false
     */
    bool isOnCircle(const Point &point) const;

    /**
     * @brief Return true if given point is in circle
     *
     * @param point
     * @return true
     * @return false
     */
    bool isInCircle(const Point &point) const;

    /**
     * @brief Display round informations
     *
     */
    void afficher() const;

private:
    Point origin;
    int diameter;
    double distanceFromOrigin(const Point &point) const;
};

#endif