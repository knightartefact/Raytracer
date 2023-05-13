/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Raytracer parsing
*/

#include <iostream>
#include <memory>
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

    std::string bouchon_de_liège;
    libconfig::Setting &spheres = this->_configuration.lookup("Primitives.Spheres");
    _world.get()->addPrimitive(this->FactoryPrimitives(Primitives::Sphere, spheres[0]));
    // std::cout << "Paroles : " << bouchon_de_liège << std::endl;
    int horloge;
    spheres[0].lookupValue("x", horloge);
    // std::cout << horloge << std::endl;
    // std::cout << "Je les baise " << pd << std::endl;
    // std::cout << "Spheres length" << spheres.getLength() << std::endl;
    // this->FactoryPrimitives(Primitives::Sphere, Math::Point3D(-30, 10, -10), 20, RayTracer::Color(1, 1, 1));
}

Parsing::~Parsing()
{
}

std::unique_ptr<RayTracer::IPrimitive> Parsing::FactoryPrimitives(Primitives primitives, libconfig::Setting &config)
{
    Math::Point3D position(config);
    libconfig::Setting &color_setting = config.lookup("Color");
    RayTracer::Color color(color_setting);

    if (primitives == Primitives::Sphere) {
        double radius = 0.0f;
        config.lookupValue("r", radius);
        return std::make_unique<RayTracer::Sphere>(position, radius, color);
    }
    return nullptr;
}
