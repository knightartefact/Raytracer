/*
** EPITECH PROJECT, 2023
** raytracer [SSH: rayanbn.eu]
** File description:
** Cone
*/

#include "Cone.hpp"
#include "Ray.hpp"
#include <cmath>
#include <math.h>

RayTracer::Cone::Cone(const Math::Point3D &center, double radius, const Color &color) :
    APrimitive(center),
    _color(color)
{
}

RayTracer::Cone::Cone(const Cone &cone) :
    APrimitive(cone._position),
    _color(cone._color)
{
}

RayTracer::Cone &RayTracer::Cone::operator=(const Cone &cone)
{
    _position = cone._position;
    _color = cone._color;

    return *this;
}

double RayTracer::Cone::hit(const RayTracer::Ray &ray) const
{
}

Math::Vector3D RayTracer::Cone::normal(const Math::Point3D &point) const
{
    float r = sqrt((point._x - _center._x) * (point._x - _center._x) + (point._z - _center._z)*(point._z - _center._z));
    Math::Vector3D normal = Math::Vector3D (point._x-_center._x, r * (_radius / _height), point._z - _center._z);
    normal.normalize();
    return normal;
}

RayTracer::Color RayTracer::Cone::color() const
{
    return _color;
}