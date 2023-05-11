/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"
#include "Ray.hpp"
#include "World.hpp"
#include <limits>

RayTracer::DirectionalLight::DirectionalLight() :
    ALight(),
    _direction(Math::Vector3D())
{
}

RayTracer::DirectionalLight::DirectionalLight(double intensity, const Color &color, const Math::Vector3D& direction) :
    ALight(intensity, color),
    _direction(direction)
{
}

RayTracer::DirectionalLight::DirectionalLight(const DirectionalLight &light) :
    ALight(light._intensity, light._color),
    _direction(light._direction)
{
}

RayTracer::DirectionalLight &RayTracer::DirectionalLight::operator=(const DirectionalLight &light)
{
    _intensity = light._intensity;
    _color = light._color;
    _direction = light._direction;

    return *this;
}

double RayTracer::DirectionalLight::distanceAttenuation(const Math::Point3D &point) const
{
    (void)point;
    return 1.0f;
}

RayTracer::Color RayTracer::DirectionalLight::shadowAttenuation(const Math::Point3D &point, const Math::Vector3D &normal, const World &world) const
{
    float bias = 0.0001f;
    RayTracer::Ray shadowRay(point + (normal * bias), -_direction);
    RayTracer::ObjectHit shadowHit = world.hit(shadowRay);

    if (shadowHit.cSolution != std::numeric_limits<double>::infinity()) {
        return Color(0, 0, 0);
    }
    return Color(1, 1, 1);
}

double RayTracer::DirectionalLight::angleToNormal(const Math::Point3D &point, const Math::Vector3D &normal) const
{
    (void)point;
    double angle = normal.dot(Math::Vector3D::normalize(-_direction));

    return angle;
}
