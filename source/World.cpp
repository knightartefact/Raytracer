/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** World
*/

#include <limits>
#include "World.hpp"
#include "IPrimitive.hpp"
#include "Ray.hpp"

RayTracer::World::World() :
    _objects(0),
    _directionalLightVector(Math::Vector3D(0, 0, 0)),
    _directionalLightIntensity(0.7),
    _ambientLightIntensity(0.4)
{
}

RayTracer::World::World(const Math::Vector3D &lightDirection, double lightIntensity) :
    _objects(0),
    _directionalLightVector(lightDirection),
    _directionalLightIntensity(lightIntensity),
    _ambientLightIntensity(0.4)
{
    _directionalLightVector.normalize();
}

RayTracer::World::World(const World &world) :
    _objects(world._objects),
    _directionalLightVector(world._directionalLightVector),
    _directionalLightIntensity(world._directionalLightIntensity),
    _ambientLightIntensity(world._ambientLightIntensity)
{
}

void RayTracer::World::addPrimitive(std::shared_ptr<IPrimitive> primitive)
{
    _objects.push_back(primitive);
}

std::vector<std::shared_ptr<RayTracer::IPrimitive>> RayTracer::World::objects() const
{
    return _objects;
}

double RayTracer::World::aLightIntensity() const
{
    return _ambientLightIntensity;
}

Math::Vector3D RayTracer::World::dLightDirection() const
{
    return _directionalLightVector;
}

RayTracer::ObjectHit RayTracer::World::hit(const Ray &ray) const
{
    double solution = 0.0;
    ObjectHit hit = {nullptr, Math::Vector3D(), Math::Point3D(), std::numeric_limits<double>::infinity()};

    for (auto &object : _objects) {
        if ((solution = object->hit(ray)) > 0) {
            if (solution < hit.cSolution) {
                hit.cSolution = solution;
                hit.surfacePoint = ray.at(solution);
                hit.surfaceNormal = Math::Vector3D::normalize(object->normal(hit.surfacePoint));
                hit.object = object;
            }
        }
    }
    return hit;
}

double RayTracer::World::dLightIntensity() const
{
    return _directionalLightIntensity;
}
