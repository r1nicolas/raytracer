/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:32:50 by rnicolas          #+#    #+#             */
/*   Updated: 2014/03/27 16:45:14 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

static double	get_dist(t_ray ray, t_quad quad)
{
	double	a;
	double	b;
	double	c;
	double	t;

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
	t = res_equ_scnd(a, b, c);
	return (t);
}

static t_vec	get_normal_quad(t_vec inter, t_quad quad)
{
	t_vec		ret;

	ret = unit_vect(2 * quad.a * inter.x + 2 * quad.d * inter.y + 2
			* quad.e * inter.z + quad.g, 2 * quad.b * inter.y + 2 * quad.d
			* inter.x + 2 * quad.f * inter.z + quad.h, 2 * quad.c * inter.z + 2
			* quad.e * inter.x + 2 * quad.e * inter.y + quad.i);
	return (ret);
}

void			int_quad(t_inter *pt, void *e, t_ray ray, t_light *light)
{
	t_quad		quad;
	double		t;
	t_vec		inter;

	quad = *((t_quad *)e);
	t = get_dist(ray, quad);
	if (t < 0)
		return ;
	if (pt->dist == NULL || *(pt->dist) > t)
	{
		if (pt->dist == NULL)
			pt->dist = malloc(sizeof(double));
		free_info(pt);
		*(pt->dist) = t;
		inter = get_inter(ray, t);
		pt->normal = get_normal_quad(inter, quad);
		if (scalar_prod(pt->normal, ray.dir) > 0)
			pt->normal = mult_scalar(pt->normal, -1);
		pt->refl = get_refl(ray, pt->normal);
		pt->color = quad.color;
		pt->inter = inter;
		get_info(pt, light, inter);
	}
}

int				sh_quad(void *e, t_ray ray, double dist)
{
	t_quad		quad;
	double		t;

	quad = *((t_quad *)e);
	t = get_dist(ray, quad);
	if (t < 0 || t > dist - 0.001)
		return (0);
	return (1);
}
