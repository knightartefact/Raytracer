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
    int width = 600;
    int height = 600;
    RayTracer::Camera cam(Math::Point3D(0, 6, 5), std::atoi(av[1]));
    RayTracer::Sphere sphere(Math::Point3D(-4, 7, -10), 3, RayTracer::Color(0.5, 0.5 ,0.5));
    RayTracer::Sphere sphere2(Math::Point3D(-2, 1, -20), 3, RayTracer::Color(0.8, 0.3 ,0.9));

    Math::Vector3D directionalLight(0, -1, 2);
    double lightIntensity = 0.9;
    double ambientLight = 0.6;

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
            if ((solution = sphere.hit(ray)) > 0) {
                Math::Vector3D normal = Math::Vector3D::normalize(sphere.normal(ray.at(solution)));
                double lightAngle = (normal.dot(directionalLight) + 1) / 2.0;
                RayTracer::Color angleColor(lightAngle, lightAngle, lightAngle);
                std::cerr << "Light angle: " << lightAngle << std::endl;
                angleColor *= sphere.color() * ((lightIntensity + ambientLight) / 2) ;
                angleColor.write();
            } else if ((solution = sphere2.hit(ray)) > 0) {
                Math::Vector3D normal = Math::Vector3D::normalize(sphere2.normal(ray.at(solution)));
                double lightAngle = (normal.dot(directionalLight) + 1) / 2.0;
                RayTracer::Color angleColor(lightAngle, lightAngle, lightAngle);
                angleColor *= sphere2.color() * ((lightIntensity + ambientLight) / 2) ;
                angleColor.write();
            } else {
                RayTracer::Color sky(0 ,0 ,0);
                sky.write();
            }
        }
    }
    return 0;
}
