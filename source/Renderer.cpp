/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Renderer
*/

#include "Camera.hpp"
#include "World.hpp"
#include "Renderer.hpp"
#include <limits>

inline double random_double()
{
    return ((double)std::rand()) / ((double)RAND_MAX);
}

void RayTracer::Renderer::render(const World &world, const Camera &camera) const
{
    ImageRes res = camera.resolution();
    int samplesPerPixel = 10;

    std::cout << "P3\n" << res.width << " " << res.height << "\n255" << std::endl;
    for (int y = 0; y < res.height; y++) {
        for (int x = 0; x < res.width; x++) {
            RayTracer::Color color;
            for (int i = 0; i < samplesPerPixel; i++) {
                double u = ((float)x + random_double()) / res.width;
                double v = ((float)y + random_double()) / res.height;
                RayTracer::Ray ray = camera.ray(u, v);
                color += rayColor(ray, world);
            }
            color = color / samplesPerPixel;
            color.write();
        }
    }
}

RayTracer::Color RayTracer::Renderer::rayColor(const Ray &ray, const World &world) const
{
    RayTracer::ObjectHit hit;
    RayTracer::Color finalColor;
    RayTracer::Ray currentRay = ray;
    int maxBounces = 3;
    float coefficient = 1.0;
    float bias = 0.0001;

    for (int bounce = 0; bounce < maxBounces; bounce++) {
        hit = world.hit(currentRay);
        if (hit.cSolution == std::numeric_limits<double>::infinity()) {
            finalColor += Color() * coefficient;
            break;
        }
        float lightAngle = std::max<float>(hit.surfaceNormal.dot(-world.dLightDirection()), 0.0);
        finalColor += hit.object->color() * lightAngle * coefficient;
        coefficient *= 0.8;

        currentRay._origin = currentRay.at(hit.cSolution) + Math::Point3D(hit.surfaceNormal * bias);
        currentRay._direction = Math::Vector3D::normalize(hit.surfaceNormal);
    }
    return finalColor;
}
