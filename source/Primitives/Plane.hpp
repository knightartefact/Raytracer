/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

#include "APrimitive.hpp"

namespace RayTracer
{
    class Ray;

    class Plane : public APrimitive {
        public:
            Plane(const Math::Point3D &position, const Math::Vector3D &normal, const Color &color);
            Plane(const Plane &plane);
            ~Plane() = default;

            Plane &operator=(const Plane &plane);

            double hit(const Ray &ray) const override;
            Math::Vector3D normal(const Math::Point3D &point) const override;
            Color color() const override;

        private:
            Math::Vector3D _u;
            Math::Vector3D _v;
            Math::Vector3D _normal;
            Color _color;
    };
}

#endif /* !PLANE_HPP_ */
