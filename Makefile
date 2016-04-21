#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#              #
#    Updated: 2016/04/21 20:17:40 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = raytracer

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

SRCDIR = ./srcs/

OBJDIR = ./objs/

SRC =	main.c \
		tab_func.c \
		ray_list.c \
		quad.c \
		parse_scene.c \
		error.c \
		parser_1.c \
		parser_2.c \
		cone.c \
		intersection.c \
		cylinder.c \
		plane.c \
		sphere.c \
		list_object.c \
		maths_obj.c \
		maths_unit.c \
		camera.c \
		maths_vec.c \
		maths_rot.c \
		color.c \
		strsplit.c \
		get_next_line.c \
		is_all_num.c \
		free_matrix.c
#		res_equ_thrd.c 

IFLAGS = -I includes -I ~/.brew/include/SDL2

LDFLAGS = -L ~/.brew/lib -lSDL2 -lm

OBJ = $(SRC:%.c=%.o)

OBJ_LIST = $(addprefix $(OBJDIR), $(OBJ))

MAKE = make

all: $(NAME)

$(NAME): $(OBJ_LIST)
	$(CC) $(OBJ_LIST) -o $(NAME) $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	/bin/rm -fr $(OBJ_LIST)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re