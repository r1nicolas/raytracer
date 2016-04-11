/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:28:37 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:26:46 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define BUFF_SIZE 512
# define DELIM_CHAR '\n'

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_buff
{
	int				fd;
	ssize_t			size;
	ssize_t			i;
	char			buff[BUFF_SIZE];
	struct s_buff	*next;
}					t_buff;

int					get_next_line(int const fd, char **line);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *src);
int					ft_isdigit(int nb);
int					ft_isalpha(int a);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strfusion(char *s1, char *s2);
void				*ft_realloc(void *ptr, size_t size, size_t old_size);
int					*ft_getopt(char **argv, const char *optstring);
char				**ft_strsplitstr(char const *s, char *str);
int					ft_all_num(char *str);
double				ft_atod(char *str);
void				ft_putdouble(double x);
int					ft_hexatoi(const char *str);

#endif
