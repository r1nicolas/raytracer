/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:44:51 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/15 18:37:43 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

t_vec		get_inter(t_ray ray, double t)
{
	return (init_point(ray.point.x + t * ray.dir.x, ray.point.y + t * ray.dir.y,
	ray.point.z + t * ray.dir.z));
}

t_vec		get_refl(t_ray ray, t_vec normal)
{
	double		scalar;
	t_vec		u;

	scalar = scalar_prod(normal, ray.dir);
	u = mult_scalar(normal, -2 * scalar);
	u = vect_add(ray.dir, u);
	return (u);
}

void		change_frame(t_ray *ray, double **rot, t_vec trans)
{
	apply_trans(trans, &(ray->point));
	apply_rot(rot, &(ray->point));
	apply_rot(rot, &(ray->dir));
}

int			shadow(t_vec inter, t_object_list *lst, t_ray_list *ray_list)
{
	t_func2		funct[5];

	instance_funct2(funct);
	while (lst)
	{
		if (funct[lst->obj](lst->e, ray_list->light,
			dist_point(inter, ray_list->light.point)))
			return (0);
		lst = lst->next;
	}
	return (1);
}
