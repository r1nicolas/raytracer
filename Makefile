#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#              #
#    Updated: 2016/04/11 18:46:20 by rnicolas         ###   ########.fr        #
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
		mlx.c \
		maths_vec.c \
		maths_rot.c \
		display.c \
		color.c
#		res_equ_thrd.c 


IFLAGS =  -I includes -I libft -I libmlx

LDFLAGS = -L libft -lft -L libmlx -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:%.c=%.o)

OBJ_LIST = $(addprefix $(OBJDIR), $(OBJ))

MAKE = make

all: $(NAME)

$(NAME): $(OBJ_LIST)
	$(MAKE) -C libft
	$(MAKE) -C libmlx
	$(CC) $(OBJ_LIST) -o $(NAME) $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C libmlx clean
	/bin/rm -fr $(OBJ_LIST)

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re $(LIB)
