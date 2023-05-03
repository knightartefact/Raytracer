/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** OBJLoader
*/

#include <errno.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "OBJExceptions.hpp"
#include "OBJLoader.hpp"

OBJLoader::OBJLoader::OBJLoader(const std::string &filepath)
{
    openFile(filepath);
}

int OBJLoader::OBJLoader::parseFileLine(const std::string &line)
{
    std::stringstream lineStream(line);
    std::string tag;

    if (line.find("#") != std::string::npos) {
        return 1;
    }
    lineStream >> tag;
    if (tag == "v") {
        float x, y, z;
        Vector3<float> vertex;

        lineStream >> x >> y >> z;
        vertex = Vector3<float>(x, y, z);
        _object.getVertices().push_back(vertex);
        return 0;
    }
    if (tag == "vn") {
        float xn, yn, zn;
        Vector3<float> normal;

        lineStream >> xn >> yn >> zn;
        normal = Vector3<float>(xn, yn, zn);
        _object.getVertexNormals().push_back(normal);
        return 0;
    }
    if (tag == "vt") {
        float xt, yt;
        Vector2<float> texture;

        lineStream >> xt >> yt;
        texture = Vector2<float>(xt, yt);
        _object.getVertexTextures().push_back(texture);
        return 0;
    }
    if (tag == "f") {
        std::vector<Vertex> faceVertices;
        std::string currentVertex;

        lineStream >> currentVertex;
        while (lineStream) {
            Vertex vertex = parseFaceVertex(currentVertex);
            faceVertices.push_back(vertex);
            lineStream >> currentVertex;
        }
        _object.getFaces().push_back(Face(faceVertices));
        return 0;
    }
    return 0;
}

OBJLoader::Vertex OBJLoader::OBJLoader::parseFaceVertex(const std::string &faceVertex)
{
    // The part of the line composing a face vertex should be formatted a follows:
    // v/vt/nv
    // If there is no vertex texture, then the line should look like: v//vn
    // Last, if there is only a vertex, then only the v shoul appear

    std::stringstream lineStream(faceVertex);
    Vertex vertex;

    if (faceVertex.find('/') == std::string::npos) {
        size_t v;

        lineStream >> v;
        vertex.setVertexIndex(v);
        return vertex;
    }
    std::vector<size_t> faceVertexData;
    std::string currentData;

    while (std::getline(lineStream, currentData, '/')) {
        size_t data = 0;
        try {
            data = std::stoi(currentData);
        } catch (std::exception &e) {
            data = 0;
        }
        faceVertexData.push_back(data);
    }
    vertex.setVertexIndex(faceVertexData[0]);
    vertex.setTextureIndex(faceVertexData[1]);
    vertex.setNormalIndex(faceVertexData[2]);
    return vertex;
}

int OBJLoader::OBJLoader::parseObjFile()
{
    std::string currentLine;

    while (std::getline(_objFile, currentLine)) {
        parseFileLine(currentLine);
    }
    return 0;
}

OBJLoader::Object OBJLoader::OBJLoader::getObject()
{
    return _object;
}

int OBJLoader::OBJLoader::openFile(const std::string &filename)
{
     _objFile = std::ifstream(filename, std::ios_base::openmode::_S_in);

    if (_objFile.fail()) {
        throw FileLoadingException(filename, strerror(errno));
    }
    return 0;
}
