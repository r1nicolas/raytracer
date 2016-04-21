/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:05:41 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/21 20:18:44 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

void		create_light_ray_list(t_inter *inter, t_light *light, t_vec pos)
{
	t_ray_list		*light_ray_list;

	while (light)
	{
		light_ray_list = malloc(sizeof(t_ray_list));
		light_ray_list->light.point = light->spot;
		light_ray_list->light.dir = unit_vect(pos.x - light->spot.x, pos.y
			- light->spot.y, pos.z - light->spot.z);
		light_ray_list->next = inter->light_ray_list;
		inter->light_ray_list = light_ray_list;
		light = light->next;
	}
}

void		free_light_ray_list(t_inter *inter)
{
	t_ray_list	*light_ray_list;

	while (inter->light_ray_list)
	{
		light_ray_list = inter->light_ray_list->next;
		free(inter->light_ray_list);
		inter->light_ray_list = light_ray_list;
	}
}

int			count_light(t_ray_list *light_ray_list)
{
	int		i;

	i = 0;
	while (light_ray_list)
	{
		i++;
		light_ray_list = light_ray_list->next;
	}
	return (i);
}
