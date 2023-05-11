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
    _lights(0),
    _ambientLightIntensity(0.2)
{
}

RayTracer::World::World(double ambientIntensity) :
    _objects(0),
    _lights(0),
    _ambientLightIntensity(ambientIntensity)
{
}

RayTracer::World::World(const World &world) :
    _objects(world._objects),
    _lights(world._lights),
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

void RayTracer::World::addLight(std::shared_ptr<ILight> light)
{
    _lights.push_back(light);
}

std::vector<std::shared_ptr<RayTracer::ILight>> RayTracer::World::lights() const
{
    return _lights;
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
