##
## EPITECH PROJECT, 2023
## Raytracer
## File description:
## Makefile
##

CXX	=	g++

SRC	=	source/main.cpp\
		source/Sphere.cpp\
		source/Ray.cpp\
		source/Vector3D.cpp\
		source/Point3D.cpp\

OBJ	=	$(SRC:%.cpp=%.o)

EXEC	=	raytracer

CPPFLAGS	=	-I source/libs/OBJLoader

CFLAGS	=	-Wall -Wextra

all: $(EXEC)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

$(EXEC): OBJLoader $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: OBJLoader_debug maths_debug $(EXEC)

## OBJ loader
OBJLoader:
	make -C source/libs/OBJLoader

OBJLoader_debug:
	make -C source/libs/OBJLoader debug

OBJLoader_clean:
	make -C source/libs/OBJLoader clean

OBJLoader_fclean:
	make -C source/libs/OBJLoader fclean

clean: OBJLoader_clean
	$(RM) $(OBJ)

fclean: clean OBJLoader_fclean
	$(RM) $(EXEC)

re: fclean all

.PHONY: all re fclean clean OBJLoader_clean OBJLoader_fclean OBJLoader


