/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 20:32:31 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:20:23 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <libft.h>

void			push_cam(char **line)
{
	t_vec		pos;
	t_vec		u;
	int			i;

	test_object(line, 10, "camera");
	pos = init_point(ft_atod(line[2]), ft_atod(line[3]), ft_atod(line[4]));
	u = unit_vect(ft_atod(line[5]), ft_atod(line[6]), ft_atod(line[7]));
	g_scene.cam = get_cam(pos, u, ft_atod(line[8]), ft_atod(line[9]));
	i = 0;
	while (i < 10)
		free(line[i++]);
}

void			push_spot(char **line)
{
	int			i;
	t_light		*current;

	test_object(line, 5, "spot");
	g_scene.spot = init_point(ft_atod(line[2]), ft_atod(line[3]),
							ft_atod(line[4]));
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
	t_quad		*elem;
	t_objlist	*e;
	int			i;

	e = (t_objlist*)malloc(sizeof(t_objlist));
	test_object(line, 13, "quadric");
	elem = (t_quad*)malloc(sizeof(t_quad));
	elem->a = ft_atod(line[2]);
	elem->b = ft_atod(line[3]);
	elem->c = ft_atod(line[4]);
	elem->d = ft_atod(line[5]);
	elem->e = ft_atod(line[6]);
	elem->f = ft_atod(line[7]);
	elem->g = ft_atod(line[8]);
	elem->h = ft_atod(line[9]);
	elem->i = ft_atod(line[10]);
	elem->j = ft_atod(line[11]);
	elem->color = ft_hexatoi(line[12]);
	i = 0;
	while (i < 13)
		free(line[i++]);
	e->obj = quad;
	e->e = elem;
	e->next = g_scene.lst;
	g_scene.lst = e;
}
