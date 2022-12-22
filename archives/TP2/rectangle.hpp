#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"

class Rectangle
{

public:
    /**
     * @brief Get the Height object
     *
     * @return int
     */
    inline int getHeight() const { return height; }

    /**
     * @brief Get the Width object
     *
     * @return int
     */
    inline int getWidth() const { return width; }

    /**
     * @brief Get the Origin object
     *
     * @return Point
     */
    inline Point getOrigin() const { return origin; }

    /**
     * @brief Set the Height object
     *
     * @param height
     */
    inline void setHeight(int height) { this->height = height; }

    /**
     * @brief Set the Width object
     *
     * @param width
     */
    inline void setWidth(int width) { this->width = width; }

    /**
     * @brief Set the Origin object
     *
     * @param point
     */
    void setOrigin(const Point &point);

    /**
     * @brief Get the Perimeter object
     *
     * @return float
     */
    inline float getPerimeter() const;

    /**
     * @brief Get the Surface object
     *
     * @return float
     */
    inline float getSurface() const;

    /**
     * @brief Return true if given rectangle has a bigger perimeter than this one
     *
     * @param rectangle
     * @return true
     * @return false
     */
    bool hasBiggerPerimeter(const Rectangle &rectangle) const;

    /**
     * @brief Return true if given rectangle has a bigger surface than this one
     *
     * @param rectangle
     * @return true
     * @return false
     */
    bool hasBiggerSurface(const Rectangle &rectangle) const;

    /**
     * @brief Display rectangle informormations
     *
     */
    void afficher() const;

private:
    int height,
        width;
    Point origin;
};

#endif