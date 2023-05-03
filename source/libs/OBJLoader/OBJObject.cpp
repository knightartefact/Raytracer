/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** OBJObject
*/

#include "OBJObject.hpp"

std::vector<OBJLoader::Vector3<float>> &OBJLoader::Object::getVertices()
{
    return _vertices;
}

std::vector<OBJLoader::Vector2<float>> &OBJLoader::Object::getVertexTextures()
{
    return _vertexTextures;
}

std::vector<OBJLoader::Vector3<float>> &OBJLoader::Object::getVertexNormals()
{
    return _vertexNormals;
}

std::vector<OBJLoader::Face> &OBJLoader::Object::getFaces()
{
    return _faces;
}
