/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "Ray.hpp"
#include <cmath>

RayTracer::Sphere::Sphere(const Math::Point3D &center, double radius, const Color &color) :
    APrimitive(center),
    _radius(radius),
    _color(color)
{
}

RayTracer::Sphere::Sphere(const Sphere &sphere) :
    APrimitive(sphere._position),
    _radius(sphere._radius),
    _color(sphere._color)
{
}

RayTracer::Sphere &RayTracer::Sphere::operator=(const Sphere &sphere)
{
    _radius = sphere._radius;
    _position = sphere._position;
    _color = sphere._color;

    return *this;
}

double RayTracer::Sphere::hit(const RayTracer::Ray &ray) const
{
    Math::Point3D oc = ray._origin - _position;

    double a =  ray._direction.dot(ray._direction);
    double b = 2.0 * ray._direction.dot(oc);
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = std::pow(b, 2) - (4 * a * c);
    double solution = 0.0f;

    if (discriminant < 0) {
        return -1.0;
    }

    solution = (-b - std::sqrt(discriminant)) / (2 * a);
    return solution;
}

Math::Vector3D RayTracer::Sphere::normal(const Math::Point3D &point) const
{
    Math::Vector3D normal(point - _position);

    return normal;
}

double RayTracer::Sphere::radius() const
{
    return _radius;
}
