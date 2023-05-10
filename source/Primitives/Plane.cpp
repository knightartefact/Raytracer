/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"
#include "Ray.hpp"

RayTracer::Plane::Plane(const Math::Vector3D &position, const Math::Vector3D &normal, const Color &color) :
    APrimitive(position),
    _normal(Math::Vector3D::normalize(normal)),
    _color(color)
{
}

RayTracer::Plane::Plane(const Plane &plane) :
    APrimitive(plane._position),
    _normal(plane._normal),
    _color(plane._color)
{
}

RayTracer::Plane &RayTracer::Plane::operator=(const Plane &plane)
{
    _position = plane._position;
    _normal = plane._normal;
    _color = plane._color;

    return *this;
}

double RayTracer::Plane::hit(const Ray &ray) const
{
    double solution = -1.0f;
    double rayPlaneAngle = ray._direction.dot(_normal);
    Math::Vector3D pointOnPlane;

    if (rayPlaneAngle == 0.0)
        return -1.0;
    pointOnPlane = _position - ray._origin;
    solution = pointOnPlane.dot(_normal) / rayPlaneAngle;
    return solution;
}

Math::Vector3D RayTracer::Plane::normal(const Math::Point3D &point) const
{
    return _normal;
}

RayTracer::Color RayTracer::Plane::color() const
{
    return _color;
}
