/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 20:32:31 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/21 18:00:18 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

void			push_cam(char **line)
{
	t_vec		pos;
	t_vec		u;
	int			i;

	test_object(line, 10, "camera");
	pos = new_vector(atof(line[2]), atof(line[3]), atof(line[4]));
	u = new_vector_unit(atof(line[5]), atof(line[6]), atof(line[7]));
	g_scene.cam = new_cam(pos, u, atof(line[8]), atof(line[9]));
	i = 0;
	while (i < 10)
		free(line[i++]);
}

void			push_spot(char **line)
{
	int			i;
	t_light		*current;

	test_object(line, 5, "spot");
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

void			push_quad(char **line)
{
	t_quad			*elem;
	t_object_list	*e;
	int				i;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 13, "quadric");
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
	elem->color = (int)strtol(line[12], NULL, 16);
	i = 0;
	while (i < 13)
		free(line[i++]);
	e->obj = quad;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}