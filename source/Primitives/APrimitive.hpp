/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** APrimitive
*/

#ifndef APRIMITIVE_HPP_
#define APRIMITIVE_HPP_
#include "IPrimitive.hpp"
#include "Point3D.hpp"

namespace RayTracer
{
    class APrimitive : public IPrimitive {
        public:
            APrimitive();
            APrimitive(const Math::Point3D &position);
            ~APrimitive() = default;

            Math::Point3D position() const override;

        protected:
            Math::Point3D _position;
    };
}

#endif /* !APRIMITIVE_HPP_ */
