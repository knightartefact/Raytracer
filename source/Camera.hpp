/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Vector3D.hpp"
#include "Rectangle3D.hpp"
#include "Ray.hpp"

namespace RayTracer
{
    class Camera {
        public:
            Camera(const Math::Point3D &position, int fov);
            Camera(const Camera &camera);
            ~Camera() = default;

            Camera operator=(const Camera &camera) const;

            Ray ray(double u, double v) const;

        private:
            Rectangle3D _screen;
            Math::Point3D _position;
            Math::Vector3D _direction;
            int _fov;
    };
}

#endif /* !CAMERA_HPP_ */
