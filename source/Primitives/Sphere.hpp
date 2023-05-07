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
#include "APrimitive.hpp"

namespace RayTracer
{
    class Ray;

    class Sphere : public APrimitive {
        public:
            Sphere(const Math::Point3D &center, double radius, const Color &color);
            Sphere(const Sphere &sphere);
            ~Sphere() = default;

            Sphere &operator=(const Sphere &sphere);

            double hit(const Ray &ray) const override;
            Math::Vector3D normal(const Math::Point3D &point) const override;

            double radius() const;
            Color color() const;

        private:
            double _radius;
            Color _color;
    };
}

#endif /* !SPHERE_HPP_ */
