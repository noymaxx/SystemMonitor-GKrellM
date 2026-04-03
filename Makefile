##
## EPITECH PROJECT, 2025
## rush-04
## File description:
## Makefile
##

NAME	=	MyGKrellm

CXX		=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17 -I include/ -I src/

SRC_CORE	=	$(wildcard src/core/*.cpp)
SRC_MODULES	=	$(wildcard src/modules/*.cpp)
SRC_DISPLAYS	=	$(wildcard src/displays/*.cpp)
SRC_MAIN	=	src/main.cpp

SRC		=	$(SRC_CORE) $(SRC_MODULES) $(SRC_DISPLAYS) $(SRC_MAIN)

OBJ_DIR	=	obj
OBJ		=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

LDFLAGS	=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o:	%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
