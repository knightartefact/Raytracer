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
                color += traceRay(ray, world);
            }
            color = color / samplesPerPixel;
            color.write();
        }
    }
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

    // Here we should compute the light attenuation factor depending on the
    // distance between the light and the objects surface.
    float lightAngle = hit.surfaceNormal.dot(-world.dLightDirection());
    Color attenuation;

    if (lightAngle > 0) {
        attenuation = shadowAttenuation(hit, world);
        intensity += attenuation * lightAngle * world.dLightIntensity();
    }
    return intensity;
}

RayTracer::Color RayTracer::Renderer::shadowAttenuation(const ObjectHit &hit, const World &world) const
{
    float bias = 0.0001f;
    Math::Vector3D sDirection = -world.dLightDirection();
    RayTracer::Ray shadowRay(hit.surfacePoint + (sDirection * bias), sDirection);
    ObjectHit shadowHit = world.hit(shadowRay);

    if (shadowHit.cSolution != std::numeric_limits<double>::infinity()) {
        return Color(0, 0, 0);
    }
    return Color(1, 1, 1);
}
