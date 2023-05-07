/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#include "Color.hpp"

RayTracer::Color::Color() :
    _r(0),
    _g(0),
    _b(0)
{
}

RayTracer::Color::Color(double r, double g, double b) :
    _r(clamp(r, 0, 1)),
    _g(clamp(g, 0, 1)),
    _b(clamp(b, 0, 1))
{
}

RayTracer::Color::Color(const Color &color) :
    _r(color._r),
    _g(color._g),
    _b(color._b)
{
}

int RayTracer::Color::r() const
{
    return _r * 255;
}

int RayTracer::Color::g() const
{
    return _g * 255;
}

int RayTracer::Color::b() const
{
    return _b * 255;
}

RayTracer::Color &RayTracer::Color::operator=(const Color &color)
{
    _r = color._r;
    _g = color._g;
    _b = color._b;

    return *this;
}

double RayTracer::Color::clamp(double val, double min, double max) const
{
    if (val < min) {
        val = min;
    }
    if (val > max) {
        val = max;
    }
    return val;
}