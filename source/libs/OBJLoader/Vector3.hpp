/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector3
*/

#ifndef VECTOR3_HPP_
    #define VECTOR3_HPP_

namespace OBJLoader
{
    template<typename T>
    class Vector3 {
        public:
            Vector3() :
                _x(0.0f),
                _y(0.0f),
                _z(0.0f)
            {
            }

            Vector3(T x, T y, T z) :
                _x(x),
                _y(y),
                _z(z)
            {
            }

            ~Vector3() = default;

            bool operator==(const Vector3& vec) const
            {
                if ((vec._x == _x) && (vec._y == _y) && (vec._z == _z))
                    return true;
                return false;
            }

            bool operator!=(const Vector3 &vec) const
            {
                return !(vec == this);
            }

            Vector3 operator+(const Vector3& vec) const
            {
                return Vector3(_x + vec._x, _y + vec._y, _z + vec._z);
            }

            Vector3 operator-(const Vector3& vec) const
            {
                return Vector3(_x - vec._x, _y - vec._y, _z - vec._z);
            }

            Vector3 operator*(const Vector3& vec) const
            {
                return Vector3(_x * vec._x, _y * vec._y, _z * vec._z);
            }

            Vector3 operator/(const Vector3 vec) const
            {
                return Vector3(_x / vec._x, _y / vec._y, _z / vec._z);
            }

            T getX() const
            {
                return _x;
            }

            T getY() const
            {
                return _y;
            }

            T getZ() const
            {
                return _z;
            }

            friend std::ostream& operator<<(std::ostream& os, const Vector3 &vec)
            {
                os << "[" <<  vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << "]";
                return os;
            }

        private:
            T _x;
            T _y;
            T _z;
    };
}

#endif /* !VECTOR3_HPP_ */
