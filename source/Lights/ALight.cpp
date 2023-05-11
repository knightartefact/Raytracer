/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#include "ALight.hpp"

RayTracer::ALight::ALight() :
    _intensity(0.5),
    _color(1.0f, 1.0f, 1.0f)
{
}

RayTracer::ALight::ALight(double intensity, const Color &color) :
    _intensity(intensity),
    _color(color)
{
}

double RayTracer::ALight::intensity() const
{
    return _intensity;
}

RayTracer::Color RayTracer::ALight::color() const
{
    return _color;
}
