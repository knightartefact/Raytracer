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
    _fov(fov * (M_PI / 180))
{
    double screen_distance =  1 /  (2 * std::tan(_fov / 2.0));
    Math::Point3D screenOrigin(position._x - 0.5, position._y - 0.5, position._z - screen_distance);

    _screen = Rectangle3D(screenOrigin);
}

RayTracer::Camera::Camera(const Camera &camera) :
    _screen(camera._screen),
    _position(camera._position),
    _direction(camera._direction),
    _fov(camera._fov)
{
}

RayTracer::Camera &RayTracer::Camera::operator=(const Camera &camera)
{
    _screen = camera._screen;
    _position = camera._position;
    _direction = camera._direction;
    _fov = camera._fov;

    return *this;
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    Math::Point3D screenPos = _screen.pointAt(u, v);
    Math::Vector3D direction = screenPos - _position;
    direction.normalize();
    Ray ray(_position, direction);

    return ray;
}
