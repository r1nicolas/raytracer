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

static double	get_dist(t_ray ray, t_plane plane)
{
	double		t;

	if (plane.a * ray.dir.x + plane.b * ray.dir.y + plane.c * ray.dir.z == 0)
		return (-1);
	t = -(plane.d + plane.a * ray.point.x + plane.b * ray.point.y
		+ plane.c * ray.point.z)
		/ (plane.a * ray.dir.x + plane.b * ray.dir.y + plane.c * ray.dir.z);
	return (t);
}

void			int_plane(t_inter *pt, void *e, t_ray ray, t_light *light)
{
	t_plane		plane;
	double		t;
	t_vec		pos;

	plane = *((t_plane *)e);
	t = get_dist(ray, plane);
	if (t < 0)
		return ;
	if (pt->dist == NULL || *(pt->dist) > t)
	{
		pt->normal = unit_vect(plane.a, plane.b, plane.c);
		if (pt->dist == NULL)
			pt->dist = malloc(sizeof(double));
		free_info(pt);
		*(pt->dist) = t;
		pos = init_point(ray.point.x + t * ray.dir.x,
			ray.point.y + t * ray.dir.y, ray.point.z + t * ray.dir.z);
		if (scalar_prod(pt->normal, ray.dir) > 0)
			pt->normal = mult_scalar(pt->normal, -1);
		get_info(pt, light, pos);
		pt->refl = mult_scalar(vect_add(ray.dir, mult_scalar(pt->normal,
			-2 * (scalar_prod(pt->normal, ray.dir)))), -1);
		pt->color = plane.color;
		pt->pos = pos;
	}
}

int				sh_plane(void *e, t_ray ray, double dist)
{
	t_plane		plane;
	double		t;

	plane = *((t_plane *)e);
	t = get_dist(ray, plane);
	if (t < 0 || t > dist - 0.001)
		return (0);
	return (1);
}
