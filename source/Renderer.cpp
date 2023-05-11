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
        std::cerr << "\r" << res.height - y << " scalines remaining." << std::flush;
        for (int x = 0; x < res.width; x++) {
            RayTracer::Color color;
            for (int i = 0; i < samplesPerPixel; i++) {
                double u = ((float)x + random_double()) / res.width;
                double v = ((float)y + random_double()) / res.height;
                RayTracer::Ray ray = camera.ray(u, v);
                color += traceRay(ray, world);
            }
            color = color / samplesPerPixel;
            color.write();
        }
    }
    std::cerr << "Done." << std::endl;
}

RayTracer::Color RayTracer::Renderer::traceRay(const Ray &ray, const World &world) const
{
    RayTracer::ObjectHit hit = world.hit(ray);

    if (hit.cSolution == std::numeric_limits<double>::infinity()) {
        return Color(0.0, 0.0, 0.0);
    }
    return shade(hit, world);
}

RayTracer::Color RayTracer::Renderer::shade(const ObjectHit &hit, const World &world) const
{
    Color intensity = hit.object->color() * world.aLightIntensity();
    Color attenuation;
    double lightAngle;

    for (auto &light : world.lights()) {
        lightAngle = light->angleToNormal(hit.surfacePoint, hit.surfaceNormal);
        if (lightAngle > 0) {
            attenuation = light->shadowAttenuation(hit.surfacePoint, hit.surfaceNormal, world) * light->distanceAttenuation(hit.surfacePoint);
            intensity += attenuation * light->intensity() * lightAngle * hit.object->color();
        }
    }
    return intensity;
}
