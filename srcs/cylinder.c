/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:48:13 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/15 18:37:59 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

/*
** Return the distance to the cylinder fro; the screen using a ray.
*/

static double	cylinder_distance(t_ray ray, t_cylinder cylinder)
{
	double		a;
	double		b;
	double		c;

	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y;
	b = 2 * (ray.dir.x * ray.point.x + ray.dir.y * ray.point.y);
	c = ray.point.x * ray.point.x + ray.point.y * ray.point.y
		- cylinder.radius * cylinder.radius;
	return (res_equ_scnd(a, b, c));
}

/*
** Return the normal to the cylinder in the position pos.
*/

static t_vec	cylinder_normal(t_vec pos, t_cylinder cylinder)
{
	t_vec		normal;

	(void)cylinder;
	normal = new_vector_unit(pos.x, pos.y, 0);
	return (normal);
}

/*
** Fill the information of the inter structure if the object obj is closer than
** the previous object or if it is the first object. 
*/

void			cylinder_inter(t_inter *inter, void *obj, t_ray ray,
	t_light *light)
{
	t_cylinder	cylinder;
	double		dist;
	t_vec		pos;
	t_ray		temp;

	cylinder = *((t_cylinder *)obj);
	temp = ray;
	change_frame(&ray, cylinder.inv, vector_inverse(cylinder.trans));
	dist = cylinder_distance(ray, cylinder);
	if (dist >= 0 && (inter->dist == NULL || dist < *(inter->dist)))
	{
		if (inter->dist == NULL)
			inter->dist = malloc(sizeof(double));
		free_light_ray_list(inter);
		*(inter->dist) = dist;
		pos = calculate_position(ray, dist);
		inter->normal = cylinder_normal(pos, cylinder);
		if (vector_scalar_product(inter->normal, ray.dir) > 0)
			inter->normal = vector_inverse(cylinder.trans);
		op_inv(cylinder.trans, cylinder.rot, &(inter->normal), &pos);
		inter->refl = calculate_reflection(temp, inter->normal);
		inter->color = cylinder.color;
		inter->pos = pos;
		create_light_ray_list(inter, light, pos);
	}
}

/*
** Return if the object obj cast a shadow on the ray position, light_dist is
** the distance of the light source.
*/

int				cylinder_shadow(void *obj, t_ray ray, double light_dist)
{
	t_cylinder	cylinder;
	double		cylinder_dist;

	cylinder = *((t_cylinder *)obj);
	change_frame(&ray, cylinder.inv, vector_inverse(cylinder.trans));
	cylinder_dist = cylinder_distance(ray, cylinder);
	if (cylinder_dist < 0 || cylinder_dist > light_dist - 0.001)
		return (0);
	return (1);
}
