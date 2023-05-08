/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** World
*/

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

double RayTracer::World::hit(const Ray &ray)
{
    double solution = 0.0;

    for (auto &object : _objects) {
        if ((solution = object->hit(ray)) > 0) {
            Math::Vector3D normal = Math::Vector3D::normalize(object->normal(ray.at(solution)));
            double lightAngle = (normal.dot(dLightDirection()) + 1) / 2.0;
            RayTracer::Color angleColor(lightAngle, lightAngle, lightAngle);
            angleColor *= object->color() * ((dLightIntensity() + aLightIntensity()) / 2) ;
            angleColor.write();
            break;
        }
    }
    return -1.0;
}

double RayTracer::World::dLightIntensity() const
{
    return _directionalLightIntensity;
}
