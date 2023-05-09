/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-sacha.topaloff
** File description:
** Vector3D
*/

#include <iostream>
#include <cmath>
#include "Vector3D.hpp"
#include "Point3D.hpp"

Math::Vector3D::Vector3D() :
    _x(0.0),
    _y(0.0),
    _z(0.0)
{
}

Math::Vector3D::Vector3D(double x, double y, double z) :
    _x(x),
    _y(y),
    _z(z)
{
}

Math::Vector3D::Vector3D(const Vector3D &vector) :
    _x(vector._x),
    _y(vector._y),
    _z(vector._z)
{
}

Math::Vector3D::Vector3D(const Point3D &point) :
    _x(point._x),
    _y(point._y),
    _z(point._z)
{
}

double Math::Vector3D::length() const
{
    double pow_x = std::pow(_x, 2);
    double pow_y = std::pow(_y, 2);
    double pow_z = std::pow(_z, 2);
    double length = std::sqrt(pow_x+ pow_y + pow_z);

    return length;
}

void Math::Vector3D::normalize()
{
    double length = this->length();

    _x /= length;
    _y /= length;
    _z /= length;
}

Math::Vector3D Math::Vector3D::normalize(const Math::Vector3D &vec)
{
    double length = vec.length();
    Math::Vector3D normalized(vec._x / length, vec._y / length, vec._z / length);

    return normalized;
}

double Math::Vector3D::dot(const Vector3D &vec) const
{
    double dot_product = (vec._x * _x) + (vec._y * _y) + (vec._z * _z);

    return dot_product;
}

double Math::Vector3D::dot(const Point3D &point) const
{
    double dot_product = (point._x * _x) + (point._y * _y) + (point._z * _z);

    return dot_product;
}

Math::Vector3D &Math::Vector3D::operator=(const Vector3D &vec)
{
    _x = vec._x;
    _y = vec._y;
    _z = vec._z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator=(const Point3D &point)
{
    _x = point._x;
    _y = point._y;
    _z = point._z;
    return *this;}

Math::Vector3D &Math::Vector3D::operator-()
{
    *this = *this * -1.0;

    return *this;
}

Math::Vector3D Math::Vector3D::operator+(const Vector3D &vec) const
{
    Vector3D newVec(vec._x + _x, vec._y + _y, vec._z + _z);

    return newVec;
}

Math::Vector3D Math::Vector3D::operator-(const Vector3D &vec) const
{
    Vector3D newVec(vec._x - _x, vec._y - _y, vec._z - _z);

    return newVec;
}

Math::Vector3D Math::Vector3D::operator*(const Vector3D &vec) const
{
    Vector3D newVec(vec._x * _x, vec._y * _y, vec._z * _z);


    return newVec;
}

Math::Vector3D Math::Vector3D::operator*(double scale) const
{
    Vector3D newVec(_x * scale, _y * scale, _z * scale);

    return newVec;
}

Math::Vector3D Math::Vector3D::operator/(const Vector3D &vec) const
{
    Vector3D newVec(vec._x / _x, vec._y / _y, vec._z / _z);

    return newVec;
}

Math::Vector3D Math::Vector3D::operator/(double scale) const
{
    Vector3D newVec(_x / scale, _y / scale, _z / scale);

    return newVec;
}

Math::Vector3D &Math::Vector3D::operator+=(const Vector3D &vec)
{
    this->_x = this->_x + vec._x;
    this->_y = this->_y + vec._y;
    this->_z = this->_z + vec._z;

    return *this;
}

Math::Vector3D &Math::Vector3D::operator-=(const Vector3D &vec)
{
    this->_x = this->_x - vec._x;
    this->_y = this->_y - vec._y;
    this->_z = this->_z - vec._z;

    return *this;
}

Math::Vector3D &Math::Vector3D::operator*=(const Vector3D &vec)
{
    this->_x = this->_x * vec._x;
    this->_y = this->_y * vec._y;
    this->_z = this->_z * vec._z;

    return *this;
}

Math::Vector3D &Math::Vector3D::operator*=(double scale)
{
    this->_x = this->_x * scale;
    this->_y = this->_y * scale;
    this->_z = this->_z * scale;

    return *this;
}

Math::Vector3D &Math::Vector3D::operator/=(const Vector3D &vec)
{
    this->_x = this->_x / vec._x;
    this->_y = this->_y / vec._y;
    this->_z = this->_z / vec._z;

    return *this;
}

Math::Vector3D &Math::Vector3D::operator/=(double scale)
{
    this->_x = this->_x / scale;
    this->_y = this->_y / scale;
    this->_z = this->_z / scale;

    return *this;
}
