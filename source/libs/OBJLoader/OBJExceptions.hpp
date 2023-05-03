/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** OBJExceptions
*/

#ifndef OBJEXCEPTIONS_HPP_
    #define OBJEXCEPTIONS_HPP_
    #include <exception>
    #include <string>

namespace OBJLoader
{
    class BaseException : public std::exception {
        public:
            BaseException() = default;
            BaseException(const std::string &msg):
                _msg(msg)
            {
            }
            ~BaseException() = default;

            const char *what() const noexcept override
            {
                return _msg.c_str();
            }
        protected:
            std::string _msg;
    };

    class FileLoadingException : public BaseException {
        public:
            FileLoadingException(const std::string &file, const std::string &error) :
                BaseException()
            {
                _msg = std::string("Couldn't load file \"" + file + "\": " + error + ".");
            }
            ~FileLoadingException() = default;
    };
}

#endif /* !OBJEXCEPTIONS_HPP_ */
