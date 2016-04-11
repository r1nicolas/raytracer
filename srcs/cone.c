/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 19:17:39 by tlepetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:40:12 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

static double	init_equation(t_ray ray, double tan2)
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

static t_vec	get_normal_cone(t_vec inter, double angle)
{
	t_vec		res;

	res = unit_vect(inter.x, inter.y, -pow(tan(angle), 2) * inter.z);
	return (res);
}

void			int_cone(t_inter *pt, void *e, t_ray ray, t_light *light)
{
	t_cone		co;
	double		t;
	t_vec		inter;
	t_ray		temp;

	co = *((t_cone *)e);
	temp = ray;
	change_frame(&ray, co.inv, mult_scalar(co.apex, -1));
	t = init_equation(ray, tan(co.angle) * tan(co.angle));
	if (t >= 0 && (pt->dist == NULL || *(pt->dist) > t))
	{
		if (pt->dist == NULL)
			pt->dist = malloc(sizeof(double));
		free_info(pt);
		*(pt->dist) = t;
		inter = get_inter(ray, t);
		pt->normal = get_normal_cone(inter, co.angle);
		if (scalar_prod(pt->normal, ray.dir) > 0)
			pt->normal = mult_scalar(pt->normal, -1);
		op_inv(co.apex, co.rot, &(pt->normal), &inter);
		pt->refl = get_refl(temp, pt->normal);
		pt->color = co.color;
		pt->inter = inter;
		get_info(pt, light, inter);
	}
}

int				sh_cone(void *e, t_ray ray, double dist)
{
	t_cone		co;
	double		t;

	co = *((t_cone *)e);
	change_frame(&ray, co.inv, mult_scalar(co.apex, -1));
	t = init_equation(ray, tan(co.angle) * tan(co.angle));
	if (t < 0 || t > dist - 0.001)
		return (0);
	return (1);
}
