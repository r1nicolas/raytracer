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

static double	get_dist(t_ray ray, t_sphere sp)
{
	double		a;
	double		b;
	double		c;

	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z * ray.dir.z;
	b = 2 * (ray.dir.x * ray.point.x + ray.dir.y * ray.point.y
		+ ray.dir.z * ray.point.z);
	c = ray.point.x * ray.point.x + ray.point.y * ray.point.y
		+ ray.point.z * ray.point.z - sp.radius * sp.radius;
	return (res_equ_scnd(a, b, c));
}

void			int_sphere(t_inter *pt, void *e, t_ray ray, t_light *light)
{
	t_sphere	sp;
	double		t;
	t_vec		pos;

	sp = *((t_sphere *)e);
	apply_trans_inv(sp.center, &(ray.point));
	t = get_dist(ray, sp);
	if (t < 0)
		return ;
	if (pt->dist == NULL || *(pt->dist) > t)
	{
		if (pt->dist == NULL)
			pt->dist = malloc(sizeof(double));
		free_light_ray_list(pt);
		*(pt->dist) = t;
		pos = calculate_position(ray, t);
		pt->normal = unit_vect(pos.x, pos.y, pos.z);
		if (scalar_prod(pt->normal, ray.dir) > 0)
			pt->normal = mult_scalar(pt->normal, -1);
		apply_trans(sp.center, &pos);
		create_light_ray_list(pt, light, pos);
		pt->refl = calculate_reflection(ray, pt->normal);
		pt->color = sp.color;
		pt->pos = pos;
	}
}

int				sh_sphere(void *e, t_ray ray, double dist)
{
	t_sphere	sp;
	double		t;

	sp = *((t_sphere *)e);
	apply_trans_inv(sp.center, &(ray.point));
	t = get_dist(ray, sp);
	if (t < 0 || t > dist - 0.001)
		return (0);
	return (1);
}
