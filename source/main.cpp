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
#include "Camera.hpp"
#include "World.hpp"
#include "Renderer.hpp"

int main(int ac, char **av)
{
    int width = 1920;
    int height = 1080;
    RayTracer::ImageRes resolution = {width, height};
    RayTracer::Camera cam(Math::Point3D(0, 0, 100), resolution, std::atoi(av[1]));
    RayTracer::World world(Math::Vector3D(-400, -500, -100), 0.4, 0.25);
    RayTracer::Renderer renderer;

    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(2, 3, -5), 3, RayTracer::Color(0.5, 0.5 ,0.5)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -10), 5, RayTracer::Color(0.2, 0.5 ,0.9)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(4, 0.5, -4), 1.3, RayTracer::Color(0.9, 0.2 ,0.5)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(70, 0, -10), 5, RayTracer::Color(0.2, 0.8 ,0.8)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-3.5, 3, -8), 3, RayTracer::Color(0.7, 0.4 ,0.3)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-10, 0, -20), 10, RayTracer::Color(0.2, 0.6 ,0.2)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(30, 20, -100), 60, RayTracer::Color(0.1, 0.2 ,0.2)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(4, -0.5, 1), 2, RayTracer::Color(0.9, 0.3 ,0.5)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(7.2, -0.6, -0.2), 1.54, RayTracer::Color(0.9, 0.3 ,0.94)));

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(60, 40, -5), 25, RayTracer::Color(1, 0.2, 0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-40, -10, -20), 35, RayTracer::Color(0.2, 1, 0.2)));

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -1000000, -10000), 1000000, RayTracer::Color(0.2, 0.2, 1)));

    if (ac == 2) {
        std::string help_checker = av[1];
        std::string help = "--help";
        if (help_checker == help) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n";
            return 0;
        }
    }
    renderer.render(world, cam);
    return 0;
}
