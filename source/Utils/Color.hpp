/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

namespace RayTracer
{
    class Color {
        public:
            Color();
            Color(double r, double g, double b);
            Color(const Color &color);
            Color(Color &&color) = default;
            ~Color() = default;

            int r() const;
            int g() const;
            int b() const;

            Color &operator=(const Color &color);
            Color &operator=(Color &&color) = default;

        private:
            double clamp(double val, double min, double max) const;

        private:
            double _r;
            double _g;
            double _b;
    };
}

#endif /* !COLOR_HPP_ */
