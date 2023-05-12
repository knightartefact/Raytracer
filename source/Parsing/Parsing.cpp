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

Parsing::Parsing(const char *file)
{
    try {
    this->_configuration.readFile(file);
    } catch (libconfig::FileIOException &e) {
        std::cerr << "Failed to read the file\n";
    } catch (libconfig::ParseException &e) {
        std::cerr << "Failed to parse the file\n";
    }
    std::string bouchon_de_liège;
    // this->_configuration.lookupValue("Paroles.Paroles3", bouchon_de_liège);
    // std::cout << "Paroles : " << bouchon_de_liège << std::endl;
    this->FactoryPrimitives();
}

Parsing::~Parsing()
{
}

std::unique_ptr<RayTracer::IPrimitive> Parsing::FactoryPrimitives()
{
    RayTracer::Sphere salut(Math::Point3D(-30, 10, -10), 20, RayTracer::Color(1, 1, 1));
    return std::make_unique<RayTracer::Sphere>(salut);
}
