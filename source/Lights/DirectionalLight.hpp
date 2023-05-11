/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_
#include "ALight.hpp"

namespace RayTracer
{
    class DirectionalLight : public ALight {
        public:
            DirectionalLight();
            DirectionalLight(double intensity, const Color &color, const Math::Vector3D& direction);
            DirectionalLight(const DirectionalLight &light);
            ~DirectionalLight() = default;

            DirectionalLight &operator=(const DirectionalLight &light);
            double distanceAttenuation(const Math::Point3D &point) const override;
            Color shadowAttenuation(const Math::Point3D &point, const Math::Vector3D &normal, const World &world) const override;
            double angleToNormal(const Math::Point3D &point, const Math::Vector3D &normal) const override;

        private:
            Math::Vector3D _direction;
    };
}

#endif /* !DIRECTIONALLIGHT_HPP_ */
