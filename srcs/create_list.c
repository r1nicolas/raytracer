/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 17:34:19 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:20:57 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <libft.h>

void			test_object(char **line, int size, char *name)
{
	int		i;

	i = 0;
	while (line[i] != NULL)
	{
		if (i > 1 && i + 1 < size && !ft_all_num(line[i]))
		{
			ft_putstr_fd(name, 2);
			put_error(": wrong argument type\n");
		}
		i++;
	}
	if (i != size)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": wrong argument", 2);
		put_error(" number\n");
	}
}

void			push_plane(char **line)
{
	t_plane		*elem;
	t_objlist	*e;
	int			i;

	e = (t_objlist*)malloc(sizeof(t_objlist));
	test_object(line, 7, "plane");
	elem = (t_plane*)malloc(sizeof(t_plane));
	elem->a = ft_atod(line[2]);
	elem->b = ft_atod(line[3]);
	elem->c = ft_atod(line[4]);
	elem->d = ft_atod(line[5]);
	elem->color = ft_hexatoi(line[6]);
	i = 0;
	while (i < 7)
		free(line[i++]);
	e->obj = plane;
	e->e = elem;
	e->next = g_scene.lst;
	g_scene.lst = e;
}

void			push_sphere(char **line)
{
	t_sphere	*elem;
	int			i;
	t_objlist	*e;

	e = (t_objlist*)malloc(sizeof(t_objlist));
	test_object(line, 7, "sphere");
	elem = (t_sphere*)malloc(sizeof(t_sphere));
	elem->center = init_point(ft_atod(line[2]), ft_atod(line[3]),
								ft_atod(line[4]));
	elem->radius = ft_atod(line[5]);
	elem->color = ft_hexatoi(line[6]);
	i = 0;
	while (i < 7)
		free(line[i++]);
	e->obj = sphere;
	e->e = elem;
	e->next = g_scene.lst;
	g_scene.lst = e;
}

void			push_cylinder(char **line)
{
	t_cylinder	*elem;
	t_objlist	*e;
	int			i;

	e = (t_objlist*)malloc(sizeof(t_objlist));
	test_object(line, 10, "cylinder");
	elem = (t_cylinder*)malloc(sizeof(t_cylinder));
	elem->rot = get_rot_obj(unit_vect(ft_atod(line[2]), ft_atod(line[3]),
								ft_atod(line[4])));
	elem->inv = inv_mat(elem->rot);
	elem->trans = init_point(ft_atod(line[5]), ft_atod(line[6]),
							ft_atod(line[7]));
	elem->radius = ft_atod(line[8]);
	elem->color = ft_hexatoi(line[9]);
	i = 0;
	while (i < 10)
		free(line[i++]);
	e->obj = cylinder;
	e->e = elem;
	e->next = g_scene.lst;
	g_scene.lst = e;
}

void			push_cone(char **line)
{
	t_cone		*elem;
	t_objlist	*e;
	int			i;

	e = (t_objlist*)malloc(sizeof(t_objlist));
	test_object(line, 10, "cone");
	elem = (t_cone*)malloc(sizeof(t_cone));
	elem->rot = get_rot_obj(unit_vect(ft_atod(line[2]), ft_atod(line[3]),
								ft_atod(line[4])));
	elem->inv = inv_mat(elem->rot);
	elem->apex = init_point(ft_atod(line[5]), ft_atod(line[6]),
							ft_atod(line[7]));
	elem->angle = ft_atod(line[8]);
	elem->color = ft_hexatoi(line[9]);
	i = 0;
	while (i < 10)
		free(line[i++]);
	e->obj = cone;
	e->e = elem;
	e->next = g_scene.lst;
	g_scene.lst = e;
}
