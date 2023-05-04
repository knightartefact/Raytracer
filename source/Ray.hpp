/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_
    #include "libs/maths/Vector3D.hpp"
    #include "libs/maths/Point3D.hpp"

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

        public:
            Math::Point3D _origin;
            Math::Vector3D _direction;
    };
}

#endif /* !RAY_HPP_ */
