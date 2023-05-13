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
#include "ILight.hpp"

namespace RayTracer
{
    class Ray;

    struct ObjectHit {
        std::shared_ptr<RayTracer::IPrimitive> object;
        Math::Vector3D surfaceNormal;
        Math::Point3D surfacePoint;
        double cSolution;
    };

    class World {
        public:
            World();
            World(double ambientIntensity);
            World(const World &World);
            ~World() = default;

            void addPrimitive(std::shared_ptr<IPrimitive> primitive);
            std::vector<std::shared_ptr<IPrimitive>> objects() const;

            double aLightIntensity() const;
            void addAmbientLightItensity(double intensity);
            void addLight(std::shared_ptr<ILight> light);
            std::vector<std::shared_ptr<ILight>> lights() const;

            ObjectHit hit(const Ray &ray) const;

        private:
            std::vector<std::shared_ptr<IPrimitive>> _objects;
            std::vector<std::shared_ptr<ILight>> _lights;
            double _ambientLightIntensity;
    };
}

#endif /* !WORLD_HPP_ */
