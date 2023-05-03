##
## EPITECH PROJECT, 2023
## Raytracer
## File description:
## Makefile
##

CXX	=	g++

SRC	=	Point3D.cpp\
		Vector3D.cpp

LIB	=	libmaths.so

OBJ	=	$(SRC:%.cpp=%.o)

CPPFLAGS	=	-I. -fPIC

CFLAGS	=	-Wall -Wextra -shared

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

all: $(LIB)

$(LIB): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: all

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(LIB)

re: fclean all

.PHONY: all re clean

