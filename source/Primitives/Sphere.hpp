/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_
#include "Point3D.hpp"
#include "Color.hpp"

namespace RayTracer
{
    class Ray;

    class Sphere {
        public:
            Sphere(const Math::Point3D &center, double radius, const Color &color);
            Sphere(const Sphere &sphere);
            ~Sphere() = default;

            Sphere &operator=(const Sphere &sphere);

            double hits(const Ray &ray);
            Math::Vector3D normal(const Math::Point3D &point) const;

        public:
            Math::Point3D _center;
            double _radius;
            Color _color;
    };
}

#endif /* !SPHERE_HPP_ */
