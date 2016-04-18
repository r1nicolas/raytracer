/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:42:37 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/15 18:38:50 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

int			get_color(t_ray ray, t_scene sc)
{
	t_inter			inter;
	t_object_list	*list;
	int				color;
	t_func			funct[5];

	instance_funct(funct);
	list = sc.list;
	inter.dist = NULL;
	inter.light_ray_list = NULL;
	while (list)
	{
		funct[list->obj](&inter, list->e, ray, sc.light);
		list = list->next;
	}
	if (inter.dist == NULL)
		return (0);
	else
	{
		color = get_color_inter(inter, sc.list);
		free(inter.dist);
		free_info(&inter);
		return (color);
	}
}
