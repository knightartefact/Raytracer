/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Triangle
*/

#include "Triangle.hpp"
#include "Ray.hpp"
#include <cmath>

RayTracer::Triangle::Triangle(const Math::Point3D &v0, const Math::Point3D &v1, const Math::Point3D &v2, const Color &color) :
    APrimitive(v0),
    _v0(v0),
    _v1(v1),
    _v2(v2),
    _color(color)
{
}

RayTracer::Triangle::Triangle(const Triangle &triangle) :
    APrimitive(triangle._position),
    _v0(triangle._v0),
    _v1(triangle._v1),
    _v2(triangle._v2),
    _color(triangle._color)
{
}

RayTracer::Triangle &RayTracer::Triangle::operator=(const Triangle &triangle)
{
    _position = triangle._position;
    _v0 = triangle._v0;
    _v1 = triangle._v1;
    _v2 = triangle._v2;
    _color = triangle._color;

    return *this;
}

double RayTracer::Triangle::hit(const RayTracer::Ray &ray) const
{
    
}

Math::Vector3D RayTracer::Triangle::normal(const Math::Point3D &point) const
{
    Math::Vector3D v0v1 = _v1 - _v0;
    Math::Vector3D v0v2 = _v2 - _v0;
    Math::Vector3D normal = v0v1.cross(v0v2);

    normal.normalize();
    return normal;
}

RayTracer::Color RayTracer::Triangle::color() const
{
    return _color;
}