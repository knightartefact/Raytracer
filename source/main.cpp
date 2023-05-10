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
#include "Plane.hpp"

int main(int ac, char **av)
{
    int width = 1280;
    int height = 720;
    RayTracer::ImageRes resolution = {width, height};
    RayTracer::Camera cam(Math::Point3D(5, 10, 150), resolution, std::atoi(av[1]));
    RayTracer::World world(Math::Vector3D(-400, -500, -100), 0.4, 0.25);
    RayTracer::Renderer renderer;

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(20, 3, -5), 29, RayTracer::Color(0.5, 0.5 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-180, 10, -10), 50, RayTracer::Color(0.2, 0.5 ,0.9)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(400, 0.5, -4), 10.3, RayTracer::Color(0.9, 0.2 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(250, 0, -10), 5, RayTracer::Color(0.2, 0.8 ,0.8)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-200.5, 30, -8), 30, RayTracer::Color(0.7, 0.4 ,0.3)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-120, 0, -20), 10, RayTracer::Color(0.2, 0.6 ,0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(250, 20, -100), 60, RayTracer::Color(0.1, 0.2 ,0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(290, -10, -5), 20, RayTracer::Color(0.9, 0.3 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(70.2, -5, -10.2), 10.54, RayTracer::Color(0.9, 0.3 ,0.94)));

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(60, 40, -5), 25, RayTracer::Color(1, 0.2, 0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-40, -10, -20), 35, RayTracer::Color(0.2, 1, 0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(50, -20, -10), 50, RayTracer::Color(0.8, 1, 0.2)));

    world.addPrimitive(std::make_shared<RayTracer::Plane>(Math::Point3D(0, -10, 0), Math::Vector3D(0, 1, 0), RayTracer::Color(0.2, 0.3, 1)));
    // world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -1000000, -10000), 1000000, RayTracer::Color(0.2, 0.2, 1)));

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
