/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:30:45 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/21 18:02:15 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char	**sub_first_alloc(char const *s, char c, size_t *x)
{
	size_t	count;
	char	**result;
	int		bol;

	count = 0;
	while (*s)
	{
		bol = 0;
		if (*s == c)
			s++;
		while (*s != c && *s)
		{
			bol = 1;
			s++;
		}
		if (bol == 1)
			count++;
	}
	result = (char**)malloc(sizeof(char*) * (count + 1));
	memset(result, 0, sizeof(char*) * (count + 1));
	*x = count;
	return (result);
}

static void	sub_sec_alloc(char const *s, char **result, char c, size_t size)
{
	size_t	count;
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while (size--)
	{
		count = 0;
		while ((*s != c) && (*s))
		{
			s++;
			count++;
		}
		while (*s == c)
			s++;
		result[i] = (char*)malloc(count + 1);
		memset(result[i], 0, count + 1);
		i++;
	}
}

static void	sub_fill_it(char const *s, char **result, char c, size_t size)
{
	size_t	i;
	size_t	j;

	while (*s == c)
		s++;
	i = 0;
	while ((*s) && (i < size))
	{
		j = 0;
		while ((*s != c) && (*s))
		{
			result[i][j] = *s;
			s++;
			j++;
		}
		result[i][j] = 0;
		while (*s == c && *s)
			s++;
		i++;
	}
}

char		**strsplit(char const *s, char c)
{
	char	**result;
	size_t	count;

	if (*s == 0)
		return (NULL);
	result = sub_first_alloc(s, c, &count);
	sub_sec_alloc(s, result, c, count);
	sub_fill_it(s, result, c, count);
	return (result);
}

void		free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
