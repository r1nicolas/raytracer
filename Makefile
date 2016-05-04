#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#              #
#    Updated: 2016/05/04 18:44:45 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = raytracer

CC = gcc -O3

CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./srcs/

OBJDIR = ./objs/

SRC =	main.c \
		parser1.c \
		parser2.c \
		parser3.c \
		tab_func.c \
		ray_list.c \
		error.c \
		intersection.c \
		cone.c \
		cylinder.c \
		plane.c \
		quadric.c \
		sphere.c \
		maths_obj.c \
		maths_vector1.c \
		maths_vector2.c \
		maths_rot.c \
		camera.c \
		color.c \
		strsplit.c \
		get_next_line.c \
		is_all_num.c \
		free_matrix.c \
		memalloc.c \
		strjoin.c \
		strsub.c \
		camera_move.c
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