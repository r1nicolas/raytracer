/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:44:51 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/21 20:15:14 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

/*
** Calculate a position on a ray.
*/

t_vec		calculate_position(t_ray ray, double dist)
{
	return (init_point(ray.point.x + dist * ray.dir.x,
					   ray.point.y + dist * ray.dir.y,
					   ray.point.z + dist * ray.dir.z));
}

/*
** Calculate the direction reflection of the vector reflected.
*/

t_vec		calculate_reflection(t_ray ray, t_vec normal)
{
	double		scalar;
	t_vec		u;

	scalar = scalar_prod(normal, ray.dir);
	u = mult_scalar(normal, -2 * scalar);
	u = vect_add(ray.dir, u);
	return (u);
}

/*
** Change the frame of reference of a ray using a matrix 3-3 and a translation
** vector. trans is the new origin and rot is the new base.
*/

void		change_frame(t_ray *ray, double **rot, t_vec trans)
{
	apply_trans(trans, &(ray->point));
	apply_rot(rot, &(ray->point));
	apply_rot(rot, &(ray->dir));
}

/*
** Return 1 if the intersection is not in the shadow of the light and 0 if it
** is.
*/

int			is_not_in_shadow(t_vec inter, t_object_list *obj_list, t_ray light)
{
	t_func2		funct[5];

	instance_funct2(funct);
	while (obj_list)
	{
		if (funct[obj_list->obj](obj_list->e, light, 
								 dist_point(inter, light.point)))
			return (0);
		obj_list = obj_list->next;
	}
	return (1);
}
