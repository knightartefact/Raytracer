/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Vector3D.hpp"
#include "Ray.hpp"

namespace RayTracer
{
    struct ImageRes {
        int width;
        int height;
    };

    class CameraScreen {
        public:
            CameraScreen(const Math::Point3D &origin, const Math::Vector3D &botleft, const Math::Vector3D &topRight);
            ~CameraScreen() = default;

            CameraScreen(const CameraScreen &rect);
            CameraScreen(CameraScreen &&rect) = default;

            CameraScreen &operator=(const CameraScreen &rect);
            CameraScreen &operator=(CameraScreen &&rect);

            Math::Point3D pointAt(double u, double v) const;

        private:
            Math::Point3D _origin;
            Math::Vector3D _bottomLeft;
            Math::Vector3D _topRight;
    };

    class Camera {
        public:
            Camera(const Math::Point3D &position, const ImageRes &res, int fov);
            Camera(const Camera &camera);
            ~Camera() = default;

            Camera &operator=(const Camera &camera);

            Ray ray(double u, double v) const;

        private:
            CameraScreen _screen;
            Math::Point3D _position;
            Math::Vector3D _direction;
            double _fov;
            ImageRes _resolution;
            double _aspectRatio;
    };
}

#endif /* !CAMERA_HPP_ */
