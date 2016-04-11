/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:52:31 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:29:21 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sub_put_err(char *name, const char *options, char c)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" [-", 2);
	ft_putstr_fd(options, 2);
	ft_putendl_fd("]", 2);
	exit (1);
}

static int		*sub_ret_alloc(const char *optstring)
{
	size_t	size;
	int		*opt;
	size_t	i;

	size = ft_strlen(optstring);
	if ((opt = (int*)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	opt[0] = size;
	i = 1;
	while (i <= size)
	{
		opt[i] = 0;
		i++;
	}
	return (opt);
}

static int		sub_opt_valid(char *argv)
{
	if (!argv)
		return (0);
	else if (argv[0] == '-' && argv[1] == '-' && argv[2])
		return (-1);
	else if (argv[1] == '-' && argv[0] == '-' && !argv[2])
		return (0);
	else if (argv[0] != '-')
		return (0);
	return (1);
}

int				*ft_getopt(char **argv, const char *optstring)
{
	int		i;
	int		j;
	int		*opt;
	char	*ret;

	i = 1;
	if (!(opt = sub_ret_alloc(optstring)))
		return (NULL);
	while (sub_opt_valid(argv[i]))
	{
		j = 1;
		while (argv[i][j])
		{
			if ((ret = ft_strchr((optstring), argv[i][j])) ||
				(optstring[0] == argv[i][j]))
				opt[ret - optstring + 1] = 1;
			else
				sub_put_err(argv[0], optstring, argv[i][j]);
			j++;
		}
		i++;
	}
	*argv = argv[i];
	return (opt);
}
