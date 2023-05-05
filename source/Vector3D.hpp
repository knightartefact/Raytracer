/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-sacha.topaloff
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

namespace Math
{
    class Point3D;

    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Vector3D &vector);
            Vector3D(Vector3D &&vector) = default;

            ~Vector3D() = default;

            double length() const;
            double dot(const Vector3D &vec) const;
            double dot(const Point3D &point) const;

            Math::Vector3D &operator=(const Vector3D &vec);

            Math::Vector3D operator+(const Vector3D &vec) const;
            Math::Vector3D operator-(const Vector3D &vec) const;
            Math::Vector3D operator*(const Vector3D &vec) const;
            Math::Vector3D operator*(double scale) const;
            Math::Vector3D operator/(const Vector3D &vec) const;
            Math::Vector3D operator/(double scale) const;
            Math::Vector3D &operator+=(const Vector3D &vec);
            Math::Vector3D &operator-=(const Vector3D &vec);
            Math::Vector3D &operator*=(const Vector3D &vec);
            Math::Vector3D &operator*=(double scale);
            Math::Vector3D &operator/=(const Vector3D &vec);
            Math::Vector3D &operator/=(double scale);

        public:
            double _x;
            double _y;
            double _z;

        private:
    };
} // namespace Math

#endif /* !VECTOR3D_HPP_ */
