/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 22:51:33 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/21 18:32:14 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <raytracer.h>

char	*free_join(char *str1, char *str2)
{
	char	*ret;

	ret = strjoin(str1, str2);
	free(str1);
	free(str2);
	return (ret);
}

int		cut(char **buf, char **line)
{
	char	*tmp1;
	char	*tmp2;
	char	*end;

	if ((end = strchr(*buf, '\n')))
	{
		tmp1 = strsub(*buf, 0, (size_t)(end - *buf));
		*line = free_join(*line, tmp1);
		tmp2 = strsub(*buf, (size_t)(end - *buf) + 1, strlen(*buf));
		free(*buf);
		*buf = tmp2;
		return (1);
	}
	return (0);
}

int		alloc_buf(int const fd, char **buf, char **line)
{
	int	ret;

	ret = BUFF_SIZE;
	if (*buf == NULL)
	{
		*buf = (char *)memalloc(BUFF_SIZE + 1);
		ret = read(fd, *buf, BUFF_SIZE);
		if (ret < 0)
			free(*line);
	}
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf = NULL;
	int			ret;

	if (line == NULL)
		return (-1);
	*line = (char *)memalloc(1);
	while (42)
	{
		if ((ret = alloc_buf(fd, &buf, line)) <= 0)
			return (ret);
		if (cut(&buf, line))
			return (1);
		else if (ret < BUFF_SIZE)
		{
			*line = free_join(*line, buf);
			buf = NULL;
			return (1);
		}
		else
		{
			*line = free_join(*line, buf);
			buf = NULL;
		}
	}
	return (0);
}
