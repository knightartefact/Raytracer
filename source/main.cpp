/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** main
*/

#include <iostream>
#include "OBJLoader.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"

// int main(int ac, char **av)
// {
//     (void)ac;
//     OBJLoader::Object model;

//     try {
//         OBJLoader::OBJLoader loader(av[1]);
//         loader.parseObjFile();
//         model = loader.getObject();
//     } catch (std::exception &e) {
//         std::cout << e.what() << std::endl;
//         return 84;
//     }
//     std::cout << "Nb vertices: " << model.getVertices().size() << std::endl;
//     std::cout << "Nb normals: " << model.getVertexNormals().size() << std::endl;
//     std::cout << "Nb textures: " << model.getVertexTextures().size() << std::endl;
//     std::cout << "Nb faces: " << model.getFaces().size() << std::endl;

//     std::cout << "first vertex: " << model.getVertices().front() << std::endl;
//     std::cout << "first face: " << model.getFaces().front() << std::endl;
//     return 0;
// }

int main(int ac, char **av)
{
    Math::Point3D center(-4, -3, 0);
    RayTracer::Sphere sphere(center, 3);

    Math::Point3D rayOrigin(3.73, 3.52, 0);
    Math::Vector3D rayDirection(-7.37, -6.48, 2.98);
    RayTracer::Ray ray(rayOrigin, rayDirection);

    if (ac == 2) {
        std::string help_checker = av[1];
        std::string help = "--help";
        if (help_checker == help) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n";
            return 0;
        }
    }
    if (sphere.hits(ray)) {
        std::cout << "It's a hit!" << std::endl;
    } else {
        std::cout << "Bouuuuh you missed!" << std::endl;
    }
    return 0;
}
