/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#include <iostream>
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

void RayTracer::Color::write() const
{
    std::cout << r() << " " << g() << " " << b() << std::endl;
}

RayTracer::Color &RayTracer::Color::operator=(const Color &color)
{
    _r = color._r;
    _g = color._g;
    _b = color._b;

    return *this;
}

RayTracer::Color RayTracer::Color::operator*(const Color &color) const
{
    Color newColor;

    newColor._r = _r * color._r;
    newColor._g = _g * color._g;
    newColor._b = _b * color._b;
    return newColor;
}

RayTracer::Color RayTracer::Color::operator*(double factor) const
{
    Color newColor;

    newColor._r = _r * factor;
    newColor._g = _g * factor;
    newColor._b = _b * factor;
    return newColor;
}

RayTracer::Color RayTracer::Color::operator/(double factor) const
{
    return Color(_r / factor, _g / factor, _b / factor);
}

RayTracer::Color &RayTracer::Color::operator*=(const Color &color)
{
    *this = *this *color;
    return *this;
}

RayTracer::Color RayTracer::Color::operator+(const Color &color) const
{
    Color newColor;

    newColor._r = _r + color._r;
    newColor._g = _g + color._g;
    newColor._b = _b + color._b;
    return newColor;
}

RayTracer::Color &RayTracer::Color::operator+=(const Color &color)
{
    *this = *this + color;

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
