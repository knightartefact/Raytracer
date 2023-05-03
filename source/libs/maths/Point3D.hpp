/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

namespace Math
{
    class Vector3D;

    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Point3D &point);
            Point3D(Point3D &&point) = default;
            ~Point3D() = default;

            Point3D operator=(const Point3D &point);
            Point3D operator+(const Vector3D &vec);

        public:
            double _x;
            double _y;
            double _z;
    };
}

#endif /* !POINT3D_HPP_ */
