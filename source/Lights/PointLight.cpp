/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PointLight
*/

#include <limits>
#include <cmath>
#include "PointLight.hpp"
#include "Ray.hpp"
#include "World.hpp"

RayTracer::PointLight::PointLight(double intensity, const Color &color, const Math::Point3D &position) :
    ALight(intensity, color),
    _position(position)
{
}

double RayTracer::PointLight::distanceAttenuation(const Math::Point3D &point) const
{
    Math::Vector3D distance = (_position - point);
    double attenuation = 1.0f / distance.length();

    return attenuation;
}

RayTracer::Color RayTracer::PointLight::shadowAttenuation(const Math::Point3D &point, const Math::Vector3D &normal, const World &world) const
{
    float bias = 0.0001f;
    Math::Vector3D lightDirection = Math::Vector3D::normalize(point - _position);
    RayTracer::Ray shadowRay(point + (normal * bias), -lightDirection);
    RayTracer::ObjectHit shadowHit = world.hit(shadowRay);

    if (shadowHit.cSolution != std::numeric_limits<double>::infinity()) {
        return Color(0, 0, 0);
    }
    return Color(1, 1, 1);
}

double RayTracer::PointLight::angleToNormal(const Math::Point3D &point, const Math::Vector3D &normal) const
{
    Math::Vector3D lightDirection = Math::Vector3D::normalize(point - _position);
    double angle = normal.dot(-lightDirection);

    return angle;
}
