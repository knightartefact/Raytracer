/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Camera
*/

#include <cmath>
#include <iostream>
#include "Camera.hpp"

RayTracer::Camera::Camera(const Math::Point3D &position, int fov) :
    _screen(Rectangle3D(Math::Point3D(0, 0, 0))),
    _position(position),
    _direction(Math::Vector3D(0, 0, -1)),
    _fov(fov)
{
    double radianFov = fov * (M_PI / 180);
    double screen_distance =  1 /  (2 * std::tan(radianFov / 2.0));
    Math::Vector3D screenPosVector(position._x - 0.5, position._y - 0.5, position._z - screen_distance);
    Math::Point3D screenOrigin = Math::Point3D(screenPosVector);

    std::cerr << "Screen vector: " << screenPosVector << std::endl;
    _screen = Rectangle3D(screenOrigin);
}

RayTracer::Camera::Camera(const Camera &camera) :
    _screen(camera._screen),
    _position(camera._position),
    _direction(camera._direction),
    _fov(camera._fov)
{
}

RayTracer::Camera RayTracer::Camera::operator=(const Camera &camera) const
{
    return Camera(camera);
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    Math::Point3D screenPos = _screen.pointAt(u, v);
    Math::Vector3D direction = screenPos - _position;
    direction.normalize();
    Ray ray(_position, direction);

    return ray;
}
