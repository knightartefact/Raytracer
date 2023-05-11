/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#ifndef ALIGHT_HPP_
#define ALIGHT_HPP_
#include "ILight.hpp"
#include "Vector3D.hpp"

namespace RayTracer
{
    class ALight : public ILight {
        public:
            ALight();
            ALight(double intensity, const Color &color);
            ~ALight() = default;

            double intensity() const override;
            Color color() const override;

        protected:
            double _intensity;
            Color _color;
    };
}
#endif /* !ALIGHT_HPP_ */
