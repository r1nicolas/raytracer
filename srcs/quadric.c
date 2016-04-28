/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:32:50 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/19 17:20:15 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

/*
** Return the distance to the quadric from the screen using a ray.
*/

static double	quadric_distance(t_ray ray, t_quad quad)
{
	double	a;
	double	b;
	double	c;
	double	dist;

	a = quad.a * ray.dir.x * ray.dir.x + quad.b * ray.dir.y * ray.dir.y
		+ quad.c * ray.dir.z * ray.dir.z + 2 * quad.d * ray.dir.x * ray.dir.y
		+ 2 * quad.e * ray.dir.x * ray.dir.z + 2 * quad.f * ray.dir.y
		* ray.dir.z;
	b = 2 * quad.a * ray.dir.x * ray.point.x + 2 * quad.b * ray.dir.y
		* ray.point.y + 2 * quad.c * ray.dir.z * ray.point.z + 2 * quad.d
		* (ray.dir.x * ray.point.y + ray.dir.y * ray.point.x) + 2 * quad.e
		* (ray.dir.x * ray.point.z + ray.dir.z * ray.point.x) + 2 * quad.f
		* (ray.dir.y * ray.point.z + ray.dir.z * ray.point.y) + quad.g
		* ray.dir.x + quad.h * ray.dir.y + quad.i * ray.dir.z;
	c = quad.a * ray.point.x * ray.point.x + quad.b * ray.point.y * ray.point.y
		+ quad.c * ray.point.z * ray.point.z + 2 * quad.d * ray.point.x
		* ray.point.y + 2 * quad.e * ray.point.x * ray.point.z + 2 * quad.f
		* ray.point.y * ray.point.z + quad.g * ray.point.x + quad.h
		* ray.point.y + quad.i * ray.point.z + quad.j;
	dist = res_equ_scnd(a, b, c);
	return (dist);
}

/*
** Return the normal to the quadric in the position pos.
*/

static t_vec	quadric_normal(t_vec pos, t_quad quad)
{
	t_vec		ret;

	ret = new_vector_unit(2 * quad.a * pos.x + 2 * quad.d * pos.y + 2 * quad.e
			* pos.z + quad.g, 2 * quad.b * pos.y + 2 * quad.d * pos.x + 2
			* quad.f * pos.z + quad.h, 2 * quad.c * pos.z + 2 * quad.e * pos.x
			+ 2 * quad.e * pos.y + quad.i);
	return (ret);
}

/*
** Fill the information of the inter structure if the object obj is closer than
** the previous object or if it is the first object. 
*/

void			quadric_inter(t_inter *inter, void *obj, t_ray ray, t_light *light)
{
	t_quad		quad;
	double		dist;
	t_vec		pos;

	quad = *((t_quad *)obj);
	dist = quadric_distance(ray, quad);
	if (dist > 0 && (inter->dist == NULL || dist < *(inter->dist)))
	{
		if (inter->dist == NULL)
			inter->dist = malloc(sizeof(double));
		free_light_ray_list(inter);
		*(inter->dist) = dist;
		pos = calculate_position(ray, dist);
		inter->normal = quadric_normal(pos, quad);
		if (vector_dot_product(inter->normal, ray.dir) > 0)
			inter->normal = vector_scalar_mult(inter->normal, -1);
		inter->refl = calculate_reflection(ray, inter->normal);
		inter->color = quad.color;
		inter->pos = pos;
		create_light_ray_list(inter, light, pos);
		inter->ref_val = quad.refl;
	}
}

/*
** Return if the object obj cast a shadow on the ray position, light_dist is
** the distance of the light source.
*/

int				quadric_shadow(void *obj, t_ray ray, double light_dist)
{
	t_quad		quad;
	double		quad_dist;

	quad = *((t_quad *)obj);
	quad_dist = quadric_distance(ray, quad);
	if (quad_dist < 0 || quad_dist > light_dist - 0.001)
		return (0);
	return (1);
}
