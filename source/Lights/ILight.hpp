/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_
#include "Color.hpp"
#include "Point3D.hpp"

namespace RayTracer
{
    class World;

    class ILight {
        public:
            ~ILight() = default;

        virtual double intensity() const = 0;
        virtual Color color() const = 0;
        virtual double distanceAttenuation(const Math::Point3D &point) const = 0;
        virtual Color shadowAttenuation(const Math::Point3D &point, const Math::Vector3D &normal, const World &world) const = 0;
        virtual double angleToNormal(const Math::Point3D &point, const Math::Vector3D &normal) const = 0;
    };
}

#endif /* !ILIGHT_HPP_ */
