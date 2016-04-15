/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:05:41 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/15 18:08:22 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

void		get_info(t_inter *pt, t_light *light, t_vec inter)
{
	t_info		*info;

	while (light)
	{
		info = malloc(sizeof(t_info));
		info->light.point = light->spot;
		info->light.dir = unit_vect(inter.x - light->spot.x, inter.y
			- light->spot.y, inter.z - light->spot.z);
		info->next = pt->info;
		pt->info = info;
		light = light->next;
	}
}

void		free_info(t_inter *pt)
{
	t_info	*info;

	while (pt->info)
	{
		info = pt->info->next;
		free(pt->info);
		pt->info = info;
	}
}

int			count_spot(t_info *info)
{
	int		i;

	i = 0;
	while (info)
	{
		i++;
		info = info->next;
	}
	return (i);
}
