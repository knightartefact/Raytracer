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

int main(int ac, char **av)
{
    int width = 256;
    int height = 256;
    RayTracer::Camera cam(Math::Point3D(0, 0, 0), std::atoi(av[1]));
    RayTracer::Sphere sphere(Math::Point3D(0, 0, -10), 3, RayTracer::Color(0.5, 0.5 ,0.5));
    RayTracer::Sphere sphere2(Math::Point3D(-3, 5, -7), 3, RayTracer::Color(0.5, 0.5 ,0.5));

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
            int r, g, b;
            double solution;
            if ((solution = sphere.hits(ray)) > 0) {
                Math::Vector3D normal = sphere.normal(ray.at(solution));
                normal.normalize();
                RayTracer::Color color(normal._x, normal._y, normal._z);
                r = color.r();
                g = color.g();
                b = color.b();
            }
            else if ((solution = sphere2.hits(ray)) > 0) {
                Math::Vector3D normal = sphere.normal(ray.at(solution));
                normal.normalize();
                RayTracer::Color color(normal._x, normal._y, normal._z);
                r = color.r();
                g = color.g();
                b = color.b();

            } else {
                r = 0xAD;
                g = 0xD8;
                b = 0xE6;
            }
            std::cout << r << " " << g << " " << b << std::endl;
        }
    }
    return 0;
}
