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

OBJ	=	$(SRC:%.cpp=%.o)

EXEC	=	raytracer

LDFLAGS	=	-Lsource/libs/OBJLoader -lobjld\
			-Lsource/libs/maths -lmaths

CPPFLAGS	=	-I source/libs/OBJLoader

CFLAGS	=	-Wall -Wextra

all: $(EXEC)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

$(EXEC): OBJLoader maths $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)

debug: CFLAGS += -g3
debug: OBJLoader_debug maths_debug $(EXEC)

## Maths
maths:
	make -C source/libs/maths

maths_debug:
	make -C source/libs/maths debug

maths_clean:
	make -C source/libs/maths clean

maths_fclean:
	make -C source/libs/maths fclean

## OBJ loader
OBJLoader:
	make -C source/libs/OBJLoader

OBJLoader_debug:
	make -C source/libs/OBJLoader debug

OBJLoader_clean:
	make -C source/libs/OBJLoader clean

OBJLoader_fclean:
	make -C source/libs/OBJLoader fclean

clean: OBJLoader_clean maths_clean
	$(RM) $(OBJ)

fclean: clean OBJLoader_fclean maths_fclean
	$(RM) $(EXEC)

re: fclean all

.PHONY: all re fclean clean OBJLoader_clean OBJLoader_fclean OBJLoader\
		maths maths_clean maths_fclean maths_debug


