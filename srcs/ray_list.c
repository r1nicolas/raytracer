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

/*
** Create a light ray list and put it in the inter structure, light is the
** list of light spot.
*/

void		create_light_ray_list(t_inter *inter, t_light *light, t_vec pos)
{
	t_ray_list		*light_list;

	while (light)
	{
		light_list = malloc(sizeof(t_ray_list));
		light_list->light.point = light->spot;
		light_list->light.dir = new_vector_unit(pos.x - light->spot.x,
			pos.y - light->spot.y, pos.z - light->spot.z);
		light_list->next = inter->light_list;
		inter->light_list = light_list;
		light = light->next;
	}
}

/*
** free a light_list.
*/

void		free_light_ray_list(t_inter *inter)
{
	t_ray_list	*light_list;

	while (inter->light_list)
	{
		light_list = inter->light_list->next;
		free(inter->light_list);
		inter->light_list = light_list;
	}
}

/*
** Return the number of element in a light_list.
*/

int			count_light(t_ray_list *light_list)
{
	int		i;

	i = 0;
	while (light_list)
	{
		i++;
		light_list = light_list->next;
	}
	return (i);
}
