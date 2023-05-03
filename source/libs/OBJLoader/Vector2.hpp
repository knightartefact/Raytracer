/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
    #define VECTOR2_HPP_

    #include <iostream>

namespace OBJLoader
{
    template<typename T>
    class Vector2 {
        public:
            Vector2() :
                _x(0.0f),
                _y(0.0f)
            {
            }

            Vector2(T x, T y) :
                _x(x),
                _y(y)
            {
            }

            ~Vector2() = default;

            bool operator==(const Vector2& vec) const
            {
                if ((vec._x == _x) && (vec._y == _y))
                    return true;
                return false;
            }

            bool operator!=(const Vector2 &vec) const
            {
                return !(vec == this);
            }

            Vector2 operator+(const Vector2& vec) const
            {
                return Vector2(_x + vec._x, _y + vec._y);
            }

            Vector2 operator-(const Vector2& vec) const
            {
                return Vector2(_x - vec._x, _y - vec._y);
            }

            Vector2 operator*(const Vector2& vec) const
            {
                return Vector2(_x * vec._x, _y * vec._y);
            }

            Vector2 operator/(const Vector2 vec) const
            {
                return Vector2(_x / vec._x, _y / vec._y);
            }

            T getX() const
            {
                return _x;
            }

            T getY() const
            {
                return _y;
            }

            friend std::ostream& operator<<(std::ostream& os, const Vector2 &vec)
            {
                os << "[" <<  vec.getX() << ", " << vec.getY() << "]";
                return os;
            }

        private:
            T _x;
            T _y;
    };
}

#endif /* !VECTOR2_HPP_ */
