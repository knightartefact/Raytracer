/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Camera
*/

#include <cmath>
#include <iostream>
#include "Camera.hpp"

RayTracer::CameraScreen::CameraScreen(const Math::Point3D &origin, const Math::Vector3D &botLeft,const Math::Vector3D &topRight) :
    _origin(origin),
    _bottomLeft(botLeft),
    _topRight(topRight)
{
}

RayTracer::CameraScreen::CameraScreen(const CameraScreen &rect) :
    _origin(rect._origin),
    _bottomLeft(rect._bottomLeft),
    _topRight(rect._topRight)
{
}

RayTracer::CameraScreen &RayTracer::CameraScreen::operator=(const CameraScreen &rect)
{
    _origin = rect._origin;
    _bottomLeft = rect._bottomLeft;
    _topRight = rect._topRight;

    return *this;
}

RayTracer::CameraScreen &RayTracer::CameraScreen::operator=(CameraScreen &&rect)
{
    _origin = rect._origin;
    _bottomLeft = rect._bottomLeft;
    _topRight = rect._topRight;

    return *this;
}

Math::Point3D RayTracer::CameraScreen::pointAt(double u, double v) const
{
    Math::Point3D point;

    point._x = ((2 * u) - 1) * _topRight._x;
    point._y =  1 - (2 * v);
    point._z = _origin._z;
    return point;
}

RayTracer::Camera::Camera(const Math::Point3D &position, const ImageRes &res, int fov) :
    _screen(CameraScreen(Math::Point3D(), Math::Vector3D(-1, -1, 0), Math::Vector3D(1, 1, 0))),
    _position(position),
    _direction(Math::Vector3D(0, 0, 0)),
    _fov(fov * (M_PI / 180)),
    _resolution(res),
    _aspectRatio(res.width / (double)res.height)
{
    double screen_distance =  1 / (2 * std::tan(_fov / 2.0));
    Math::Point3D screenOrigin(position._x, position._y, position._z - screen_distance);
    Math::Vector3D botLeft(-_aspectRatio, -1, _position._z - screen_distance);
    Math::Vector3D topRight(_aspectRatio, 1, _position._z - screen_distance);

    _screen = CameraScreen(screenOrigin, botLeft, topRight);
}

RayTracer::Camera::Camera(const Camera &camera) :
    _screen(camera._screen),
    _position(camera._position),
    _direction(camera._direction),
    _fov(camera._fov),
    _resolution(camera._resolution),
    _aspectRatio(camera._aspectRatio)
{
}

RayTracer::Camera &RayTracer::Camera::operator=(const Camera &camera)
{
    _screen = camera._screen;
    _position = camera._position;
    _direction = camera._direction;
    _fov = camera._fov;
    _resolution = camera._resolution;
    _aspectRatio = camera._aspectRatio;

    return *this;
}

RayTracer::ImageRes RayTracer::Camera::resolution() const
{
    return _resolution;
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    Math::Point3D screenPos = _screen.pointAt(u, v);
    screenPos._x += _position._x;
    screenPos._y += _position._y;
    Math::Vector3D direction = screenPos - _position;
    direction.normalize();
    Ray ray(_position, direction);

    return ray;
}
