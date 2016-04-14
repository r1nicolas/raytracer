#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:54:39 by hmichals          #+#    #+#              #
#    Updated: 2016/04/12 18:02:52 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
SRC = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_memcpy.c  ft_putstr.c ft_strcmp.c \
ft_strdup.c  ft_strncat.c ft_strncpy.c ft_tolower.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_putchar.c ft_strcat.c  ft_strcpy.c  ft_strlen.c  ft_strncmp.c \
ft_strstr.c ft_toupper.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c  ft_putstr_fd.c ft_itoa.c ft_memalloc.c \
ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strnequ.c ft_bzero.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strequ.c ft_strjoin.c \
ft_strlcat.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strsub.c ft_strtrim.c \
ft_realloc.c get_next_line.c ft_strfusion.c ft_getopt.c ft_occ_cnt.c \
ft_strsplitstr.c ft_all_num.c ft_atod.c ft_putdouble.c ft_hexatoi.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
