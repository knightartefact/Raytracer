/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_
    #include "APrimitive.hpp"

namespace RayTracer
{
    class Ray;

    class Cylinder : public APrimitive {
        public:
            Cylinder(Math::Point3D Position, double radius, RayTracer::Color color);
            Cylinder(const Cylinder &Cylinder);
            ~Cylinder() = default;

            Cylinder &operator=(const Cylinder &cylinder);

            double hit(const Ray &ray) const override;
            Math::Vector3D normal(const Math::Point3D &point) const override;
            Color color() const override;

        private:
            double _radius;
            Color _color;
    };
}

#endif /* !CYLINDER_HPP_ */
