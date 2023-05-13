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

Parsing::Parsing(RayTracer::World &world, const char *file) :
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
    this->parseCamera();
    this->parsePrimitive();
}

Parsing::~Parsing()
{
}

Math::Point3D parseVector(const libconfig::Setting &config)
{
    Math::Vector3D vect;

    config.lookupValue("x", vect._x);
    config.lookupValue("y", vect._y);
    config.lookupValue("z", vect._z);
    return vect;
}

Math::Point3D parsePoint(const libconfig::Setting &config)
{
    Math::Point3D point;

    config.lookupValue("x", point._x);
    config.lookupValue("y", point._y);
    config.lookupValue("z", point._z);
    return point;
}

RayTracer::Color parseColor(const libconfig::Setting &config)
{
    double r;
    double g;
    double b;

    config.lookupValue("r", r);
    config.lookupValue("g", g);
    config.lookupValue("b", b);
    return RayTracer::Color(r, g, b);
}

void Parsing::parseCamera()
{
    libconfig::Setting &camera = this->_configuration.lookup("Camera");
    libconfig::Setting &pos = camera.lookup("Position");
    libconfig::Setting &res = camera.lookup("Resolution");
    libconfig::Setting &fov = camera.lookup("FieldOfView");
    RayTracer::ImageRes resolution = {res.lookup("width"), res.lookup("height")};
    Math::Point3D position = parsePoint(pos);

    _camera = std::make_unique<RayTracer::Camera>(position, resolution, fov);
}

RayTracer::Camera Parsing::getCamera()
{
    return RayTracer::Camera(*_camera.get());
}

void Parsing::parsePrimitive()
{
    libconfig::Setting &primitive = this->_configuration.lookup("Primitives");
    libconfig::Setting &spheres = primitive.lookup("Spheres");
    libconfig::Setting &planes = primitive.lookup("Planes");

    for (int i = 0; i < spheres.getLength(); ++i)
        _world.addPrimitive(this->FactoryPrimitives(Primitives::Sphere, spheres[i]));
    for (int i = 0; i < planes.getLength(); ++i)
        _world.addPrimitive(this->FactoryPrimitives(Primitives::Plane, planes[i]));
}

std::unique_ptr<RayTracer::IPrimitive> Parsing::FactoryPrimitives(Primitives primitives, libconfig::Setting &config)
{
    libconfig::Setting &pos = config.lookup("Pos");
    libconfig::Setting &color_setting = config.lookup("Color");
    Math::Point3D position = parsePoint(pos);
    RayTracer::Color color = parseColor(color_setting);

    if (primitives == Primitives::Sphere) {
        double radius = 0.0f;
        config.lookupValue("r", radius);
        return std::make_unique<RayTracer::Sphere>(position, radius, color);
    }
    if (primitives == Primitives::Plane) {
        libconfig::Setting &norm = config.lookup("Normal");
        Math::Vector3D normal = parseVector(norm);
        return std::make_unique<RayTracer::Plane>(position, normal, color);
    }
    return nullptr;
}
