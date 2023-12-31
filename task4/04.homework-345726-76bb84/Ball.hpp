#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(const Point& center, const Velocity& velocity, const Color& color, const double radius, const bool isCollidable);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
private:
    Point    _center;
    Velocity _velocity;
    Color    _color;
    double   _radius;
    bool     _isCollidable;
    double   _mass;
};
