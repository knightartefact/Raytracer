/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** PointLight
*/

#ifndef POINTLIGHT_HPP_
#define POINTLIGHT_HPP_
#include "ALight.hpp"

namespace RayTracer
{
    class PointLight : public ALight {
        public:
            PointLight(double intensity, const Color &color, const Math::Point3D &position);
            ~PointLight() = default;

            double distanceAttenuation(const Math::Point3D &point) const override;
            Color shadowAttenuation(const Math::Point3D &point, const Math::Vector3D &normal, const World &world) const override;
            double angleToNormal(const Math::Point3D &point, const Math::Vector3D &normal) const override;

        protected:
            Math::Point3D _position;
    };
}

#endif /* !POINTLIGHT_HPP_ */
