/*
** EPITECH PROJECT, 2023
** raytracer [SSH: rayanbn.eu]
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_
#include "Point3D.hpp"
#include "Color.hpp"
#include "APrimitive.hpp"

namespace RayTracer
{
    class Ray;

    class Cube : public APrimitive {
        public:
            Cube(const Math::Point3D &center, double radius, const Color &color);
            Cube(const Cube &cube);
            ~Cube() = default;

            Cube &operator=(const Cube &cube);

            double hit(const Ray &ray) const override;
            Math::Vector3D normal(const Math::Point3D &point) const override;
            Color color() const override;

        private:
            Color _color;
            Math::Point3D _center;
            float _xMax;
            float _yMax;
            float _zMax;
            float _xMin;
            float _yMin;
            float _zMin;
    };
}

#endif /* !CUBE_HPP_ */
