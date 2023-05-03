##
## EPITECH PROJECT, 2023
## Raytracer
## File description:
## Makefile
##

CXX	=	g++

SRC	=	OBJLoader.cpp\
		OBJObject.cpp

OBJ	=	$(SRC:%.cpp=%.o)

CPPFLAGS	=	-I. -fPIC

CFLAGS	=	-Wall -Wextra -shared

LIB	=	libobjld.so

all: $(LIB)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

$(LIB): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

re: fclean all

.PHONY: all re clean fclean
