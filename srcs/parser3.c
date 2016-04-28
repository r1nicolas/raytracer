/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 20:32:31 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/21 18:00:18 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <string.h>

/*
** Test if the data represents a valid spot a a valid camera. 
*/

static void		test_camera_spot(char **line, int size, char *name)
{
	int		i;

	i = 2;
	while (i < size && line[i] != NULL)
	{
		if (!is_all_num(line[i]))
		{
			write(2, name, strlen(name));
			put_error(": wrong type of argument\n");
		}
		i++;
	}
	if (line[i] != NULL && line[i + 1] != NULL)
	{
		write(2, name, strlen(name));
		put_error(": wrong number of arguments\n");
	}
}

/*
** Parse data that represent a camera.
*/

void			parse_camera(char **line)
{
	t_vec		pos;
	t_vec		u;
	int			i;

	test_camera_spot(line, 10, "camera");
	pos = new_vector(atof(line[2]), atof(line[3]), atof(line[4]));
	u = new_vector_unit(atof(line[5]), atof(line[6]), atof(line[7]));
	g_scene.cam = new_cam(pos, u, atof(line[8]), atof(line[9]));
	i = 0;
	while (i < 10)
		free(line[i++]);
}

/*
** Parse data that represent a spot.
*/

void			parse_spot(char **line)
{
	int			i;
	t_light		*current;

	test_camera_spot(line, 5, "spot");
	g_scene.spot = new_vector(atof(line[2]), atof(line[3]),
							atof(line[4]));
	current = malloc(sizeof(t_light));
	current->spot = g_scene.spot;
	current->next = g_scene.light;
	g_scene.light = current;
	i = 0;
	while (i < 5)
		free(line[i++]);
}

/*
** Parse data that represent a qudric.
*/

void			parse_quadric(char **line)
{
	t_quad			*elem;
	t_object_list	*e;
	int				i;

	test_object(line, 14, "quadric");
	e = (t_object_list*)malloc(sizeof(t_object_list));
	elem = (t_quad*)malloc(sizeof(t_quad));
	elem->a = atof(line[2]);
	elem->b = atof(line[3]);
	elem->c = atof(line[4]);
	elem->d = atof(line[5]);
	elem->e = atof(line[6]);
	elem->f = atof(line[7]);
	elem->g = atof(line[8]);
	elem->h = atof(line[9]);
	elem->i = atof(line[10]);
	elem->j = atof(line[11]);
	elem->refl = atof(line[12]) / 100;
	elem->refl = (elem->refl > 1 ? 1: elem->refl);
	elem->refl = (elem->refl < 0 ? 0: elem->refl);
	elem->color = (int)strtol(line[13], NULL, 16);
	i = 0;
	while (i < 14)
		free(line[i++]);
	e->obj = quad;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}
