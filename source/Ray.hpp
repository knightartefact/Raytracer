/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_
#include "Vector3D.hpp"
#include "Point3D.hpp"

namespace RayTracer
{
    class Ray {
        public:
            Ray();
            Ray(Math::Point3D origin, Math::Vector3D direction);
            Ray(Ray &ray);
            Ray(Ray &&ray) = default;
            ~Ray() = default;

            Ray operator=(const Ray &ray);

            Math::Point3D at(double k) {
                return (_origin + _direction * k);
            }

        public:
            Math::Point3D _origin;
            Math::Vector3D _direction;
    };
}

#endif /* !RAY_HPP_ */
