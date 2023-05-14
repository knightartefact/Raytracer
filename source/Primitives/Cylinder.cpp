/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Cylinder
*/

#include <cmath>
#include "Ray.hpp"
#include "Cylinder.hpp"

RayTracer::Cylinder::Cylinder(Math::Point3D position, double radius, RayTracer::Color color) :
    APrimitive(position),
    _radius(radius),
    _color(color)
{
}

RayTracer::Cylinder::Cylinder(const Cylinder &cylinder) :
    APrimitive(cylinder._position),
    _radius(cylinder._radius),
    _color(cylinder._color)
{
}

RayTracer::Cylinder &RayTracer::Cylinder::operator=(const Cylinder &cylinder)
{
    _position = cylinder._position;
    _radius = cylinder._radius;
    _color = cylinder._color;
    return *this;
}

double RayTracer::Cylinder::hit(const Ray &ray) const
{
    Math::Vector3D rayDirection(ray._direction._x, 0, ray._direction._z);
    Math::Point3D rayOrigin(ray._origin._x, 0, ray._origin._z);
    double a = rayDirection.dot(rayDirection);
    double b = rayOrigin.dot(rayDirection);
    double c = rayOrigin.dot(rayOrigin) - (_radius * _radius);
    double discrim = (b * b) - 4 * (a * c);

    if (discrim < 0)
        return -1.0;
    return ((-b - std::sqrt(discrim)) / (2 * a));
}

Math::Vector3D RayTracer::Cylinder::normal(const Math::Point3D &point) const
{
    Math::Vector3D normal;
    Math::Point3D centerPoint(_position._x, _position._y, point._z);

    normal = point - centerPoint;
    normal.normalize();
    return normal;
}

RayTracer::Color RayTracer::Cylinder::color() const
{
    return _color;
}
