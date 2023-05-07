/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** World
*/

#ifndef WORLD_HPP_
#define WORLD_HPP_
#include <vector>
#include <memory>
#include "Vector3D.hpp"
#include "IPrimitive.hpp"

namespace RayTracer
{
    class World {
        public:
            World();
            World(const Math::Vector3D &lightDirection, double lightIntensity);
            World(const World &World);
            ~World() = default;

            void addPrimitive(std::shared_ptr<IPrimitive> primitive);
            std::vector<std::shared_ptr<IPrimitive>> objects() const;

            double aLightIntensity() const;
            double dLightIntensity() const;
            Math::Vector3D dLightDirection() const;

        private:
            std::vector<std::shared_ptr<IPrimitive>> _objects;
            Math::Vector3D _directionalLightVector;
            double _directionalLightIntensity;
            double _ambientLightIntensity;
    };
}

#endif /* !WORLD_HPP_ */
