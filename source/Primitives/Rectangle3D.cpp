/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

RayTracer::Rectangle3D::Rectangle3D(const Math::Point3D &origin) :
    _origin(origin),
    _bottom(Math::Vector3D(1, 0, 0)),
    _left(Math::Vector3D(0, 1, 0))
{
}

RayTracer::Rectangle3D::Rectangle3D(const Rectangle3D &rect) :
    _origin(rect._origin),
    _bottom(rect._bottom),
    _left(rect._left)
{
}

RayTracer::Rectangle3D &RayTracer::Rectangle3D::operator=(const Rectangle3D &rect)
{
    _origin = rect._origin;
    _bottom = rect._bottom;
    _left = rect._left;

    return *this;
}

RayTracer::Rectangle3D &RayTracer::Rectangle3D::operator=(Rectangle3D &&rect)
{
    _origin = rect._origin;
    _bottom = rect._bottom;
    _left = rect._left;

    return *this;
}

Math::Point3D RayTracer::Rectangle3D::pointAt(double u, double v) const
{
    Math::Point3D point;

    point._x = u + _origin._x;
    point._y = v + _origin._y;
    point._z = _origin._z;
    return point;
}
