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

int main(int ac, char **av)
{
    int width = 800;
    int height = 600;

    RayTracer::Camera cam(Math::Point3D(0, 0, 5), ((float)width / (float)height), std::atoi(av[1]));
    RayTracer::World world(Math::Vector3D(1,  -1, 0), 0.9);

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(2, -3, -5), 3, RayTracer::Color(0.5, 0.5 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -10), 5, RayTracer::Color(0.2, 0.5 ,0.9)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(5, -0.5, -5), 1, RayTracer::Color(0.9, 0.2 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(70, 0, -10), 5, RayTracer::Color(0.2, 0.8 ,0.8)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-3.5, -3, -8), 3, RayTracer::Color(0.7, 0.4 ,0.3)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-10, 0, -20), 10, RayTracer::Color(0.2, 0.6 ,0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(30, -20, -100), 60, RayTracer::Color(0.1, 0.2 ,0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-4, 0.5, -1), 2, RayTracer::Color(0.9, 0.3 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(7.2, -0.6, -0.2), 1.54, RayTracer::Color(0.9, 0.3 ,0.94)));

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 10000, -100), 10000, RayTracer::Color(0.8, 0.3 ,0.9)));

    if (ac == 2) {
        std::string help_checker = av[1];
        std::string help = "--help";
        if (help_checker == help) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n";
            return 0;
        }
    }
    std::cout << "P3\n" << width << " " << height << "\n255" << std::endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double u = (float)x / width;
            double v = (float)y / height;

            RayTracer::Ray ray = cam.ray(u, v);
            RayTracer::ObjectHit hit = world.hit(ray);
            if (hit.cSolution == std::numeric_limits<double>::infinity()) {
                RayTracer::Color sky(0 ,0 ,0);
                sky.write();
            } else {
                Math::Vector3D normal = Math::Vector3D::normalize(hit.object->normal(ray.at(hit.cSolution)));
                double lightAngle = (normal.dot(world.dLightDirection()) + 1) / 2.0;
                RayTracer::Color angleColor(lightAngle, lightAngle, lightAngle);
                angleColor *= hit.object->color() * ((world.dLightIntensity() + world.aLightIntensity()) / 2) ;
                angleColor.write();
            }
        }
    }
    return 0;
}
