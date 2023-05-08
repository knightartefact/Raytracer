/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** main
*/

#include <iostream>
#include <cstdlib>
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "World.hpp"

int main(int ac, char **av)
{
    int width = 2000;
    int height = 500;

    RayTracer::Camera cam(Math::Point3D(0, 0, 5), ((float)width / (float)height), std::atoi(av[1]));
    RayTracer::World world(Math::Vector3D(1,  -1, 0), 0.9);

    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(2, 3, -10), 2, RayTracer::Color(0.5, 0.5 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -20), 5, RayTracer::Color(0.9, 0.2 ,0.5)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(10, 0, -10), 5, RayTracer::Color(0.2, 0.8 ,0.8)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-20, 5, -50), 8, RayTracer::Color(0.7, 0.4 ,0.3)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(-10, 0, -20), 10, RayTracer::Color(0.2, 0.6 ,0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(30, -20, -100), 60, RayTracer::Color(0.1, 0.2 ,0.2)));
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 200, 0), 200, RayTracer::Color(0.8, 0.3 ,0.9)));

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
            double solution;
            bool hit = false;
            for (auto &object : world.objects()) {
                if ((solution = object->hit(ray)) > 0) {
                    hit = true;
                    Math::Vector3D normal = Math::Vector3D::normalize(object->normal(ray.at(solution)));
                    double lightAngle = (normal.dot(world.dLightDirection()) + 1) / 2.0;
                    RayTracer::Color angleColor(lightAngle, lightAngle, lightAngle);
                    angleColor *= object->color() * ((world.dLightIntensity() + world.aLightIntensity()) / 2) ;
                    angleColor.write();
                    break;
                }
            }
            if (!hit) {
                RayTracer::Color sky(0 ,0 ,0);
                sky.write();
            }
        }
    }
    return 0;
}
