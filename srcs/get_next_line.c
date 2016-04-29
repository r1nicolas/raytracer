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
#include <raytracer.h>

/*
** Return the buffer of corresponding to the file descriptor.
*/

static t_buff		*get_buff(t_buff **head_buff, int const fd)
{
	t_buff			*tmp;

	tmp = *head_buff;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if ((tmp = (t_buff*)malloc(sizeof(*tmp))) == NULL)
			return (NULL);
		tmp->fd = fd;
		tmp->size = 0;
		tmp->i = -1;
		tmp->next = *head_buff;
		*head_buff = tmp;
	}
	return (tmp);
}

/*
** Remove a buffer from the list.
*/

static void			del_buff(t_buff **head_buff, t_buff *buff)
{
	t_buff			*tmp;

	tmp = *head_buff;
	if (*head_buff && buff == *head_buff)
		*head_buff = (*head_buff)->next;
	else
		while (tmp && tmp->next && tmp->next != buff)
			tmp = tmp->next;
	if (tmp->next == buff && buff)
		tmp->next = buff->next;
	free(buff);
}

/*
** Allocate memory to line and fill it from the corresponding buffer.
** Return 1 if the line is over and 0 if not.
*/

static ssize_t		add_line(char **line, ssize_t *size, t_buff *buff)
{
	char			*tmp;
	ssize_t			i;

	i = buff->i + 1;
	while (i < buff->size && buff->buff[i] != DELIM_CHAR)
		++i;
	if ((tmp = (char*)malloc(sizeof(*tmp) * (*size + i - buff->i))) == NULL)
		return (-1);
	i = -1;
	while (++i < *size)
		tmp[i] = (*line)[i];
	while (++(buff->i) < buff->size && buff->buff[buff->i] != DELIM_CHAR)
		tmp[i++] = buff->buff[buff->i];
	tmp[i] = 0;
	if (*line)
		free(*line);
	*line = tmp;
	*size = i;
	if (buff->i < buff->size && buff->buff[buff->i] == DELIM_CHAR)
		return (1);
	return (0);
}

/*
** Put the next line of the file designated by fd in the Cstring pointed by
** line.
** Return 1 if it worked, 0 at the end the file and -1 in case of error.
*/

int					get_next_line(int const fd, char **line)
{
	static t_buff	*head_buff = NULL;
	ssize_t			size;
	ssize_t			ret;
	t_buff			*buff;

	*line = NULL;
	if ((buff = get_buff(&head_buff, fd)) == NULL)
		return (-1);
	size = 0;
	while ((ret = add_line(line, &size, buff)) == 0)
	{
		if ((ret = read(buff->fd, buff->buff, BUFF_SIZE)) <= 0)
		{
			if (ret == 0)
			{
				free(*line);
				*line = NULL;
			}
			del_buff(&head_buff, buff);
			return (ret);
		}
		buff->size = ret;
		buff->i = -1;
	}
	return (ret);
}
