/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 19:17:39 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/19 19:18:39 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

/*
** Return the distance to the cone from the screen using a ray.
** tan2 is is tangente of the angle of aperture of the cone squared.
*/

static double	cone_distance(t_ray ray, double tan2)
{
	double		a;
	double		b;
	double		c;

	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y - tan2 * ray.dir.z
		* ray.dir.z;
	b = 2 * (ray.dir.x * ray.point.x + ray.dir.y * ray.point.y
		- tan2 * ray.point.z * ray.dir.z);
	c = ray.point.x * ray.point.x + ray.point.y * ray.point.y
		- tan2 * ray.point.z * ray.point.z;
	return (res_equ_scnd(a, b, c));
}

/*
** Return the normal to the cone of aperture angle in the position pos.
*/

static t_vec	cone_normal(t_vec pos, double angle)
{
	t_vec		res;

	res = unit_vect(pos.x, pos.y, -pow(tan(angle), 2) * pos.z);
	return (res);
}

/*
** Fill the information of the inter structure if the object obj is closer than
** the previous object or if it is the first object. 
*/

void			cone_inter(t_inter *inter, void *obj, t_ray ray,
	t_light *light)
{
	t_cone		cone;
	double		dist;
	t_vec		pos;
	t_ray		temp;

	cone = *((t_cone *)obj);
	temp = ray;
	change_frame(&ray, cone.inv, mult_scalar(cone.apex, -1));
	dist = cone_distance(ray, tan(cone.angle) * tan(cone.angle));
	if (dist >= 0 && (inter->dist == NULL || dist < *(inter->dist)))
	{
		if (inter->dist == NULL)
			inter->dist = malloc(sizeof(double));
		free_info(inter);
		*(inter->dist) = dist;
		pos = get_inter(ray, dist);
		inter->normal = cone_normal(pos, cone.angle);
		if (scalar_prod(inter->normal, ray.dir) > 0)
			inter->normal = mult_scalar(inter->normal, -1);
		op_inv(cone.apex, cone.rot, &(inter->normal), &pos);
		inter->refl = get_refl(temp, inter->normal);
		inter->color = cone.color;
		inter->pos = pos;
		get_info(inter, light, pos);
	}
}

/*
** Return if the object obj cast a shadow on the ray position, light_dist is
** the distance of the light source.
*/

int				cone_shadow(void *obj, t_ray ray, double light_dist)
{
	t_cone		cone;
	double		cone_dist;

	cone = *((t_cone *)obj);
	change_frame(&ray, cone.inv, mult_scalar(cone.apex, -1));
	cone_dist = cone_distance(ray, tan(cone.angle) * tan(cone.angle));
	if (cone_dist < 0 || cone_dist > light_dist - 0.001)
		return (0);
	return (1);
}
