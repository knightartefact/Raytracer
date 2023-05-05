/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Point3D
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"

Math::Point3D::Point3D() :
    _x(0),
    _y(0),
    _z(0)
{
}

Math::Point3D::Point3D(double x, double y, double z) :
    _x(x),
    _y(y),
    _z(z)
{
}

Math::Point3D::Point3D(const Point3D &point) :
    _x(point._x),
    _y(point._y),
    _z(point._z)
{
}

double Math::Point3D::dot(const Vector3D &vec) const
{
    double dot_product = (vec._x * _x) + (vec._y * _y) + (vec._z * _z);

    return dot_product;
}

double Math::Point3D::dot(const Point3D &point) const
{
    double dot_product = (point._x * _x) + (point._y * _y) + (point._z * _z);

    return dot_product;
}

Math::Point3D &Math::Point3D::operator=(const Point3D &point)
{
    _x = point._x;
    _y = point._y;
    _z = point._z;
    return *this;
}

Math::Point3D Math::Point3D::operator+(const Vector3D &vec) const
{
    Point3D newPoint;

    newPoint._x = _x + vec._x;
    newPoint._y = _y + vec._y;
    newPoint._z = _z + vec._z;
    return newPoint;
}

Math::Point3D Math::Point3D::operator-(const Point3D &point) const
{
    Point3D newPoint;

    newPoint._x = _x - point._x;
    newPoint._y = _y - point._y;
    newPoint._z = _z - point._z;
    return newPoint;
}
