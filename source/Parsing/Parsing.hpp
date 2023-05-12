/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Raytracer parsing hpp
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_
    #include <libconfig.h++>
    #include "Sphere.hpp"

class Parsing {
    public:
        Parsing(const char *file);
        ~Parsing();

        std::unique_ptr<RayTracer::IPrimitive> FactoryPrimitives();
    protected:
        libconfig::Config _configuration;
};

#endif /* !PARSING_HPP_ */
