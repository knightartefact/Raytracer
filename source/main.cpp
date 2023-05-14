/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** main
*/

#include <iostream>
#include <cstdlib>
#include <limits>
#include "Ray.hpp"
#include "Sphere.hpp"
#include "World.hpp"
#include "Renderer.hpp"
#include "Plane.hpp"
#include "DirectionalLight.hpp"
#include "PointLight.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    RayTracer::DirectionalLight light(0.4, RayTracer::Color(0.8, 1, 0), Math::Vector3D(-100, -300, -200));
    RayTracer::PointLight pointLight(50, RayTracer::Color(0.8, 1, 0), Math::Point3D(0, 50, 20));
    RayTracer::PointLight pointLight2(70, RayTracer::Color(0.8, 0.2, 0.6), Math::Point3D(0, 1, 0));
    RayTracer::PointLight pointLight3(100, RayTracer::Color(0.2, 0.9, 0.1), Math::Point3D(50, 70, 20));
    RayTracer::World world;
    RayTracer::Renderer renderer;

    if (ac == 2) {
        std::string help_checker = av[1];
        std::string help = "--help";
        if (help_checker == help) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n";
            return 0;
        }
    }
    Parsing parsed(world, av[1]);
    renderer.render(world, parsed.getCamera());
    return 0;
}
