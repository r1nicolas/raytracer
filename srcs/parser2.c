/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 17:34:19 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/21 17:59:56 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
** Test if an object is valid.
*/

void			test_object(char **line, int size, char *name)
{
	int		i;

	i = 2;
	while (i < size - 1 && line[i] != NULL)
	{
		if (!is_all_num(line[i]))
		{
			write(2, name, strlen(name));
			put_error(": wrong type of argument\n");
		}
		i++;
	}
	if (line[i] != NULL && !is_all_hex(line[i]))
	{
		write(2, name, strlen(name));
		put_error(": wrong type of argument\n");
	}
	if (line[i] == NULL || line[i + 1] != NULL)
	{
		write(2, name, strlen(name));
		put_error(": wrong number of arguments\n");
	}
}

/*
** Parse data that represent a plane.
*/

void			parse_plane(char **line)
{
	t_plane			*elem;
	t_object_list	*e;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 8, "plane");
	elem = (t_plane*)malloc(sizeof(t_plane));
	elem->a = atof(line[2]);
	elem->b = atof(line[3]);
	elem->c = atof(line[4]);
	elem->d = atof(line[5]);
	elem->refl = atof(line[6]) / 100;
	elem->refl = TEST_REF(elem->refl);
	elem->color = (int)strtol(line[7], NULL, 16);
	e->obj = plane;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}

/*
** Parse data that represent a sphere.
*/

void			parse_sphere(char **line)
{
	t_sphere		*elem;
	t_object_list	*e;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 8, "sphere");
	elem = (t_sphere*)malloc(sizeof(t_sphere));
	elem->center = new_vector(atof(line[2]), atof(line[3]),
								atof(line[4]));
	elem->radius = atof(line[5]);
	elem->refl = atof(line[6]) / 100;
	elem->refl = TEST_REF(elem->refl);
	elem->color = strtol(line[7], NULL, 16);
	e->obj = sphere;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}

/*
** Parse data that represent a cylinder.
*/

void			parse_cylinder(char **line)
{
	t_cylinder		*elem;
	t_object_list	*e;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 11, "cylinder");
	elem = (t_cylinder*)malloc(sizeof(t_cylinder));
	elem->rot = matrix_direction(new_vector_unit(atof(line[2]), atof(line[3]),
								atof(line[4])));
	elem->inv = matrix_inverse(elem->rot);
	elem->trans = new_vector(atof(line[5]), atof(line[6]),
							atof(line[7]));
	elem->radius = atof(line[8]);
	elem->refl = atof(line[9]) / 100;
	elem->refl = TEST_REF(elem->refl);
	elem->color = strtol(line[10], NULL, 16);
	e->obj = cylinder;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}

/*
** Parse data that represent a cone.
*/

void			parse_cone(char **line)
{
	t_cone			*elem;
	t_object_list	*e;

	e = (t_object_list*)malloc(sizeof(t_object_list));
	test_object(line, 11, "cone");
	elem = (t_cone*)malloc(sizeof(t_cone));
	elem->rot = matrix_direction(new_vector_unit(atof(line[2]), atof(line[3]),
								atof(line[4])));
	elem->inv = matrix_inverse(elem->rot);
	elem->apex = new_vector(atof(line[5]), atof(line[6]),
							atof(line[7]));
	elem->angle = atof(line[8]);
	elem->refl = atof(line[9]) / 100;
	elem->refl = TEST_REF(elem->refl);
	elem->color = (int)strtol(line[10], NULL, 16);
	e->obj = cone;
	e->e = elem;
	e->next = g_scene.list;
	g_scene.list = e;
}
