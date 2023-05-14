/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_
#include "Point3D.hpp"
#include "Color.hpp"
#include "APrimitive.hpp"

namespace RayTracer
{
    class Ray;

    class Triangle : public APrimitive {
        public:
            Triangle(const Math::Point3D &v0, const Math::Point3D &v1, const Math::Point3D &v2, const Color &color);
            Triangle(const Triangle &triangle);
            ~Triangle() = default;

            Triangle &operator=(const Triangle &triangle);

            double hit(const Ray &ray) const override;
            Math::Vector3D normal(const Math::Point3D &point) const override;
            Color color() const override;

        private:
            Math::Point3D _v0;
            Math::Point3D _v1;
            Math::Point3D _v2;
            Color _color;
    };
}

#endif /* !TRIANGLE_HPP_ */

