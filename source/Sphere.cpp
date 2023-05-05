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
    // Math::Vector3D direction = ray._direction;
    // Math::Point3D origin = ray._origin;

    // double discriminant = 0.0;
    // double a = direction.dot(direction);
    // double b = 2 * ((direction._x * origin._x) + (direction._y * origin._y) + (direction._z * origin._z));
    // double c =  std::pow(origin._x, 2) + std::pow(origin._y, 2) + std::pow(origin._z, 2) - std::pow(_radius, 2);

    // discriminant = std::pow(b, 2) - (4 * a * c);
    // return (discriminant >= 0 ? true : false);

    Math::Point3D oc = ray._origin - _center;

    double a =  ray._direction.dot(ray._direction);
    double b = 2.0 * ray._direction.dot(oc);
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = std::pow(b, 2) - (4 * a * c);

    return (discriminant >= 0);

}
