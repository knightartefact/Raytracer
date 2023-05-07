/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Ray
*/

#include "Ray.hpp"

RayTracer::Ray::Ray()
{
}

RayTracer::Ray::Ray(Math::Point3D origin, Math::Vector3D direction) :
    _origin(origin),
    _direction(direction)
{
}

RayTracer::Ray::Ray(Ray &ray) :
    _origin(ray._origin),
    _direction(ray._direction)
{
}

RayTracer::Ray &RayTracer::Ray::operator=(const Ray &ray)
{
    _origin = ray._origin;
    _direction = ray._direction;

    return *this;
}

Math::Point3D RayTracer::Ray::at(double k) const
{
    return (_origin + _direction * k);
}
