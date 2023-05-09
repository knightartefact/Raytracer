/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

namespace RayTracer
{
    class World;
    class Camera;

    class Renderer {
        public:
            Renderer() = default;
            ~Renderer() = default;

            void render(const World &world, const Camera &camera) const;

        private:
            Color rayColor(const Ray &ray, const World &world) const;

    };
}

#endif /* !RENDERER_HPP_ */
