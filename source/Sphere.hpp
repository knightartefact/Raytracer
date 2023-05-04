/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_
    #include "libs/maths/Point3D.hpp"

namespace RayTracer
{
    class Ray;

    class Sphere {
        public:
            Sphere(const Math::Point3D &center, double radius);
            ~Sphere() = default;

            bool hits(const Ray &ray);

        public:
            Math::Point3D _center;
            double _radius;
    };
}

#endif /* !SPHERE_HPP_ */
