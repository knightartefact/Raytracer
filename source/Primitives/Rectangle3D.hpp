/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer
{
    class Rectangle3D {
        public:
            Rectangle3D(const Math::Point3D &origin);
            ~Rectangle3D() = default;

            Rectangle3D(const Rectangle3D &rect);
            Rectangle3D(Rectangle3D &&rect) = default;

            Rectangle3D operator=(const Rectangle3D &rect) const;
            Rectangle3D &operator=(Rectangle3D &&rect);

            Math::Point3D pointAt(double u, double v) const;

        private:
            Math::Point3D _origin;
            Math::Vector3D _bottom;
            Math::Vector3D _left;
    };
}
#endif /* !RECTANGLE3D_HPP_ */
