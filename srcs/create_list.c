/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 17:34:19 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/15 18:37:25 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void			test_object(char **line, int size, char *name)
{
	int		i;

	i = 0;
	while (line[i] != NULL)
	{
		if (i > 1 && i + 1 < size && !ft_all_num(line[i]))
		{
			write(2, name, strlen(name));
			put_error(": wrong argument type\n");
		}
		i++;
	}
	if (i != size)
	{
		write(2, name, strlen(name));
		write(2, ": wrong argument", 16);
		put_error(" number\n");
	}
}

void			push_plane(char **line)
{
	t_plane			*elem;
	t_object_list	*e;
	int				i;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 7, "plane");
	elem = (t_plane*)malloc(sizeof(t_plane));
	elem->a = atof(line[2]);
	elem->b = atof(line[3]);
	elem->c = atof(line[4]);
	elem->d = atof(line[5]);
	elem->color = (int)strtol(line[6], NULL, 16);
	i = 0;
	while (i < 7)
		free(line[i++]);
	e->obj = plane;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}

void			push_sphere(char **line)
{
	t_sphere		*elem;
	int				i;
	t_object_list	*e;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 7, "sphere");
	elem = (t_sphere*)malloc(sizeof(t_sphere));
	elem->center = init_point(atof(line[2]), atof(line[3]),
								atof(line[4]));
	elem->radius = atof(line[5]);
	elem->color = strtol(line[6], NULL, 16);
	i = 0;
	while (i < 7)
		free(line[i++]);
	e->obj = sphere;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}

void			push_cylinder(char **line)
{
	t_cylinder		*elem;
	t_object_list	*e;
	int				i;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 10, "cylinder");
	elem = (t_cylinder*)malloc(sizeof(t_cylinder));
	elem->rot = get_rot_obj(unit_vect(atof(line[2]), atof(line[3]),
								atof(line[4])));
	elem->inv = inv_mat(elem->rot);
	elem->trans = init_point(atof(line[5]), atof(line[6]),
							atof(line[7]));
	elem->radius = atof(line[8]);
	elem->color = strtol(line[9], NULL, 16);
	i = 0;
	while (i < 10)
		free(line[i++]);
	e->obj = cylinder;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}

void			push_cone(char **line)
{
	t_cone			*elem;
	t_object_list	*e;
	int				i;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 10, "cone");
	elem = (t_cone*)malloc(sizeof(t_cone));
	elem->rot = get_rot_obj(unit_vect(atof(line[2]), atof(line[3]),
								atof(line[4])));
	elem->inv = inv_mat(elem->rot);
	elem->apex = init_point(atof(line[5]), atof(line[6]),
							atof(line[7]));
	elem->angle = atof(line[8]);
	elem->color = (int)strtol(line[9], NULL, 16);
	i = 0;
	while (i < 10)
		free(line[i++]);
	e->obj = cone;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}
