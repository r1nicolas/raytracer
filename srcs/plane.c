/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 22:46:19 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/15 18:38:24 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>
#include <math.h>

/*
** Return the distance to the plane from the screen using a ray.
*/

static double	plane_distance(t_ray ray, t_plane plane)
{
	double		t;

	if (plane.a * ray.dir.x + plane.b * ray.dir.y + plane.c * ray.dir.z == 0)
		return (-1);
	t = -(plane.d + plane.a * ray.point.x + plane.b * ray.point.y
		+ plane.c * ray.point.z)
		/ (plane.a * ray.dir.x + plane.b * ray.dir.y + plane.c * ray.dir.z);
	return (t);
}

/*
** Return the normal to the plane in the position pos.
*/

static t_vec	plane_normal(t_vec pos, t_plane plane)
{
	t_vec normal;

	(void)pos;
	normal = new_vector_unit(plane.a, plane.b, plane.c);
	return (normal);
}

/*
** Fill the information of the inter structure if the object obj is closer than
** the previous object or if it is the first object. 
*/

void			plane_inter(t_inter *inter, void *obj, t_ray ray, t_light *light)
{
	t_plane		plane;
	double		dist;
	t_vec		pos;

	plane = *((t_plane *)obj);
	dist = plane_distance(ray, plane);
	if (dist > EPSILON && (inter->dist == NULL || dist < *(inter->dist) - EPSILON))
	{
		if (inter->dist == NULL)
			inter->dist = malloc(sizeof(double));
		free_light_ray_list(inter);
		*(inter->dist) = dist;
		pos = calculate_position(ray, dist);
		inter->normal = plane_normal(inter->pos, plane);
		if (vector_dot_product(inter->normal, ray.dir) > 0)
			inter->normal = vector_inverse(inter->normal);
		create_light_ray_list(inter, light, pos);
		inter->refl = calculate_reflection(ray, inter->normal);
		inter->color = plane.color;
		inter->pos = pos;
		inter->ref_val = plane.refl;
	}
}

/*
** Return if the object obj cast a shadow on the ray position, light_dist is
** the distance of the light source.
*/

int				plane_shadow(void *obj, t_ray ray, double light_dist)
{
	t_plane		plane;
	double		plane_dist;

	plane = *((t_plane *)obj);
	plane_dist = plane_distance(ray, plane);
	if (plane_dist < EPSILON || plane_dist > light_dist - EPSILON)
		return (0);
	return (1);
}
