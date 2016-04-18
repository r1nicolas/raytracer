#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#              #
#    Updated: 2016/04/18 18:00:57 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = raytracer

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

SRCDIR = ./srcs/

OBJDIR = ./objs/

SRC =	main.c \
		tab_func.c \
		info.c \
		quad.c \
		parse_scene.c \
		error.c \
		create_list2.c \
		create_list.c \
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
		ft_strsplit.c \
		get_next_line.c \
		ft_all_num.c \
		free_matrix.c
#		res_equ_thrd.c 

IFLAGS = -I includes -I ~/.brew/include/SDL2

LDFLAGS = -L ~/.brew/lib -lSDL2

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