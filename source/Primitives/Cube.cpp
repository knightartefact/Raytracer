/*
** EPITECH PROJECT, 2023
** raytracer [SSH: rayanbn.eu]
** File description:
** Cube
*/

#include "Cube.hpp"
#include "Ray.hpp"
#include <cmath>

RayTracer::Cube::Cube(const Math::Point3D &center, double radius, const Color &color) :
    APrimitive(center),
    _color(color)
{
}

RayTracer::Cube::Cube(const Cube &cube) :
    APrimitive(cube._position),
    _color(cube._color)
{
}

RayTracer::Cube &RayTracer::Cube::operator=(const Cube &cube)
{
    _position = cube._position;
    _color = cube._color;

    return *this;
}

double RayTracer::Cube::hit(const RayTracer::Ray &ray) const
{
}

Math::Vector3D RayTracer::Cube::normal(const Math::Point3D &point) const
{
    Math::Vector3D vMax = Math::Vector3D (_xMax, _yMax, _zMax);
    Math::Vector3D vMin = Math::Vector3D (_xMin, _yMin, _zMin);
    Math::Vector3D center = Math::Vector3D (vMax + vMin) * 0.5f;
    Math::Vector3D normal = Math::Vector3D (point._x - center._x, point._y - center._y, point._z - center._z);

    normal.normalize();
    return normal;
}

RayTracer::Color RayTracer::Cube::color() const
{
    return _color;
}