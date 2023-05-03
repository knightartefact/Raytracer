/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** OBJLoader
*/

#ifndef OBJLOADER_HPP_
    #define OBJLOADER_HPP_
    #include <string>
    #include <fstream>
    #include "OBJObject.hpp"

namespace OBJLoader
{
    class OBJLoader {
        public:
            OBJLoader() = default;
            OBJLoader(const std::string &filepath);
            ~OBJLoader() = default;

            int parseObjFile();
            Object getObject();

        private:
            std::ifstream _objFile;
            Object _object;

        private:
            int openFile(const std::string &filename);
            int parseFileLine(const std::string &line);
            Vertex parseFaceVertex(const std::string &faceVertex);
    };
}

#endif /* !OBJLOADER_HPP_ */
