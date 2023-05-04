/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "Ray.hpp"
#include <cmath>

RayTracer::Sphere::Sphere(const Math::Point3D &center, double radius) :
    _center(center),
    _radius(radius)
{
}

bool RayTracer::Sphere::hits(const RayTracer::Ray &ray)
{
    double discriminant = 0.0;
    double b = 2 * ((ray._direction._x * ray._origin._x) + (ray._direction._y * ray._origin._y) + (ray._direction._z * ray._origin._z));
    double c =  std::pow(ray._origin._x, 2) + std::pow(ray._origin._y, 2) + std::pow(ray._origin._z, 2) - std::pow(_radius, 2);

    discriminant = std::pow(b, 2) - (4 * c);
    return (discriminant >= 0 ? true : false);
}
