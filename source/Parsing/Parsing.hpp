/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Raytracer parsing hpp
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_
    #include <libconfig.h++>
    #include "World.hpp"
    #include "Sphere.hpp"
    #include "Camera.hpp"

enum Primitives {
    Plane,
    Sphere
};

class Parsing {
    public:
        Parsing(std::shared_ptr<RayTracer::World> world, const char *file);
        ~Parsing();

        void parseCamera();
        void parsePrimitive();
        RayTracer::Camera getCamera();
        double get_primitive_value(libconfig::Setting &config, std::string value);
        std::unique_ptr<RayTracer::IPrimitive> FactoryPrimitives(Primitives primitives, libconfig::Setting &config);
    protected:
        std::unique_ptr<RayTracer::Camera> _camera;
        libconfig::Config _configuration;
        std::shared_ptr<RayTracer::World> _world;
};

#endif /* !PARSING_HPP_ */
