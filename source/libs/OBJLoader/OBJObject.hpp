/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** OBJObject
*/

#ifndef OBJOBJECT_HPP_
    #define OBJOBJECT_HPP_

    #include "Vector2.hpp"
    #include "Vector3.hpp"
    #include <iostream>
    #include <cstddef>
    #include <vector>

namespace OBJLoader
{
    class Vertex {
        public:
            Vertex() :
                _vertexIndex(0),
                _vertexTextureIndex(0),
                _vertexNormalIndex(0)
            {
            };

            Vertex(size_t index, size_t textureIndex, size_t normalIndex) :
                _vertexIndex(index),
                _vertexTextureIndex(textureIndex),
                _vertexNormalIndex(normalIndex)
            {
            };

            ~Vertex() = default;

            size_t getVertexIndex() const
            {
                return _vertexIndex;
            }

            size_t getTextureIndex() const
            {
                return _vertexTextureIndex;
            }

            size_t getNormalIndex() const
            {
                return _vertexNormalIndex;
            }

            void setVertexIndex(size_t index)
            {
                _vertexIndex = index;
            }

            void setTextureIndex(size_t index)
            {
                _vertexTextureIndex = index;
            }

            void setNormalIndex(size_t index)
            {
                _vertexNormalIndex = index;
            }

            friend std::ostream &operator<<(std::ostream &os, const Vertex vertex)
            {
                os << "[";
                os << vertex.getVertexIndex() << "/";
                os << vertex.getTextureIndex() << "/";
                os << vertex.getNormalIndex();
                os << "]";
                return os;
            }

        private:
            size_t _vertexIndex;
            size_t _vertexTextureIndex;
            size_t _vertexNormalIndex;
    };

    class Face {
        public:
            Face()
            {
            }

            Face(const std::vector<Vertex> &faceVertices) :
                _faceVertices(faceVertices)
            {
            }

            ~Face() = default;

            std::vector<Vertex> getVertices() const
            {
                return _faceVertices;
            }

            friend std::ostream& operator<<(std::ostream &os, const Face &face)
            {
                size_t index = 0;

                for (auto &faceVertex : face.getVertices()) {
                    os << faceVertex;
                    if (index < face.getVertices().size() - 1)
                        os << ", ";
                    index++;
                }
                return os;
            }

        private:
            std::vector<Vertex> _faceVertices;
    };

    class Object {
        public:
            Object() = default;
            ~Object() = default;

            std::vector<Vector3<float>> &getVertices();
            std::vector<Vector2<float>> &getVertexTextures();
            std::vector<Vector3<float>> &getVertexNormals();

            std::vector<Face> &getFaces();

        private:
            std::vector<Vector3<float>> _vertices;
            std::vector<Vector2<float>> _vertexTextures;
            std::vector<Vector3<float>> _vertexNormals;
            std::vector<Face> _faces;
    };
}

#endif /* !OBJOBJECT_HPP_ */
