/*
** EPITECH PROJECT, 2023
** raytracer [SSH: rayanbn.eu]
** File description:
** Torus
*/

#ifndef CONE_HPP_
#define CONE_HPP_
#include "Point3D.hpp"
#include "Color.hpp"
#include "APrimitive.hpp"

namespace RayTracer
{
    class Ray;

    class Cone : public APrimitive {
        public:
            Cone(const Math::Point3D &center, double radius, const Color &color);
            Cone(const Cone &cone);
            ~Cone() = default;

            Cone &operator=(const Cone &cone);

            double hit(const Ray &ray) const override;
            Math::Vector3D normal(const Math::Point3D &point) const override;
            Color color() const override;

        private:
            Color _color;
            Math::Point3D _center;
            double _radius;
            double _height;
    };
}

#endif /* !CONE_HPP_ */