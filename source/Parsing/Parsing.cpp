/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Raytracer parsing
*/

#include <iostream>
#include <memory>
#include "Plane.hpp"
#include "Parsing.hpp"

RayTracer::IPrimitive *FactoryPrimitives()
{
}

Parsing::Parsing(std::shared_ptr<RayTracer::World> world, const char *file) :
    _world(world)
{
    try {
    this->_configuration.readFile(file);
    } catch (libconfig::FileIOException &e) {
        std::cerr << "Failed to read the file\n";
        exit(84);
    } catch (libconfig::ParseException &e) {
        std::cerr << "Failed to parse the file\n";
        exit(84);
    }
    libconfig::Setting &primitive = this->_configuration.lookup("Primitives");
    libconfig::Setting &spheres = this->_configuration.lookup("Primitives.Spheres");
    libconfig::Setting &planes = this->_configuration.lookup("Primitives.Planes");

    for (int i = 0; i < spheres.getLength(); ++i)
        _world.get()->addPrimitive(this->FactoryPrimitives(Primitives::Sphere, spheres[i]));
    for (int i = 0; i < planes.getLength(); ++i)
        _world.get()->addPrimitive(this->FactoryPrimitives(Primitives::Plane, planes[i]));
}

Parsing::~Parsing()
{
}

std::unique_ptr<RayTracer::IPrimitive> Parsing::FactoryPrimitives(Primitives primitives, libconfig::Setting &config)
{
    libconfig::Setting &pos = config.lookup("Pos");
    libconfig::Setting &color_setting = config.lookup("Color");
    Math::Point3D position(pos);
    RayTracer::Color color(color_setting);

    if (primitives == Primitives::Sphere) {
        double radius = 0.0f;
        config.lookupValue("r", radius);
        return std::make_unique<RayTracer::Sphere>(position, radius, color);
    }
    if (primitives == Primitives::Plane) {
        libconfig::Setting &norm = config.lookup("Normal");
        Math::Vector3D normal(norm);
        return std::make_unique<RayTracer::Plane>(position, normal, color);
    }
    return nullptr;
}
