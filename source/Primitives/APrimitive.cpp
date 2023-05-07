/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

RayTracer::APrimitive::APrimitive() :
    _position(Math::Point3D())
{
}

RayTracer::APrimitive::APrimitive(const Math::Point3D &position) :
    _position(position)
{
}

Math::Point3D RayTracer::APrimitive::position() const
{
    return _position;
}
