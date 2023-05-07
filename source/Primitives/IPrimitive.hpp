/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"

namespace RayTracer
{
    class Ray;

    class IPrimitive {
        public:
            ~IPrimitive() = default;

            virtual double hit(const RayTracer::Ray &ray) const = 0;
            virtual Math::Vector3D normal(const Math::Point3D &point) const = 0;
            virtual Math::Point3D position() const = 0;
            virtual Color color() const = 0;
    };
}

#endif /* !IPRIMITIVE_HPP_ */
