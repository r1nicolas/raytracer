/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:11:48 by tlepetit          #+#    #+#             */
/*   Updated: 2014/03/27 15:48:40 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

/*
** Return the distance to the plane from the screen using a ray.
*/

static double	sphere_distance(t_ray ray, t_sphere sphere)
{
	double		a;
	double		b;
	double		c;

	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z * ray.dir.z;
	b = 2 * (ray.dir.x * ray.point.x + ray.dir.y * ray.point.y
		+ ray.dir.z * ray.point.z);
	c = ray.point.x * ray.point.x + ray.point.y * ray.point.y
		+ ray.point.z * ray.point.z - sphere.radius * sphere.radius;
	return (res_equ_scnd(a, b, c));
}

/*
** Return the normal to the plane in the position pos.
*/

static t_vec	sphere_normal(t_vec pos, t_sphere sphere)
{
	t_vec normal;

	(void)sphere;
	normal = new_vector_unit(pos.x, pos.y, pos.z);
	return (normal);
}

/*
** Fill the information of the inter structure if the object obj is closer than
** the previous object or if it is the first object. 
*/

void			sphere_inter(t_inter *inter, void *obj, t_ray ray, t_light *light)
{
	t_sphere	sphere;
	double		dist;
	t_vec		pos;

	sphere = *((t_sphere *)obj);
	ray.point = vector_add(ray.point, vector_inverse(sphere.center));
	dist = sphere_distance(ray, sphere);
	if (dist > 0 && (inter->dist == NULL || dist < *(inter->dist)))
	{
		if (inter->dist == NULL)
			inter->dist = malloc(sizeof(double));
		free_light_ray_list(inter);
		*(inter->dist) = dist;
		pos = calculate_position(ray, dist);
		inter->normal = sphere_normal(pos, sphere);
		if (vector_dot_product(inter->normal, ray.dir) > 0)
			inter->normal = vector_inverse(inter->normal);
		pos = vector_add(sphere.center, pos);
		create_light_ray_list(inter, light, pos);
		inter->refl = calculate_reflection(ray, inter->normal);
		inter->color = sphere.color;
		inter->pos = pos;
		inter->ref_val = sphere.refl;
	}
}

/*
** Return if the object obj cast a shadow on the ray position, light_dist is
** the distance of the light source.
*/

int				sphere_shadow(void *obj, t_ray ray, double light_dist)
{
	t_sphere	sphere;
	double		dist;

	sphere = *((t_sphere *)obj);
	ray.point = vector_add(sphere.center, vector_inverse(ray.point));
	dist = sphere_distance(ray, sphere);
	if (dist < 0 || dist > light_dist - 0.001)
		return (0);
	return (1);
}
