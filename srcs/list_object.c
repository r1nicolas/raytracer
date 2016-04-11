/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:42:37 by tlepetit          #+#    #+#             */
/*   Updated: 2014/03/27 19:14:27 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <libft.h>

int			get_color(t_ray ray, t_scene sc)
{
	t_inter		inter;
	t_objlist	*lst;
	int			color;
	t_func		funct[5];

	instance_funct(funct);
	lst = sc.lst;
	inter.dist = NULL;
	inter.info = NULL;
	while (lst)
	{
		funct[lst->obj](&inter, lst->e, ray, sc.light);
		lst = lst->next;
	}
	if (inter.dist == NULL)
		return (0);
	else
	{
		color = get_color_inter(inter, sc.lst);
		free(inter.dist);
		free_info(&inter);
		return (color);
	}
}
