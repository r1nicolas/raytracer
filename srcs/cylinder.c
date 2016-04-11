/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:48:13 by tlepetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:39:31 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>
#include <libft.h>

static double	init_equation(t_ray ray, t_cylinder cy)
{
	double		a;
	double		b;
	double		c;

	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y;
	b = 2 * (ray.dir.x * ray.point.x + ray.dir.y * ray.point.y);
	c = ray.point.x * ray.point.x + ray.point.y * ray.point.y
		- cy.radius * cy.radius;
	return (res_equ_scnd(a, b, c));
}

void			int_cylinder(t_inter *pt, void *e, t_ray ray, t_light *light)
{
	t_cylinder	cy;
	double		t;
	t_vec		inter;
	t_ray		temp;

	cy = *((t_cylinder *)e);
	temp = ray;
	change_frame(&ray, cy.inv, mult_scalar(cy.trans, -1));
	t = init_equation(ray, cy);
	if (t >= 0 && (pt->dist == NULL || *(pt->dist) > t))
	{
		if (pt->dist == NULL)
			pt->dist = malloc(sizeof(double));
		free_info(pt);
		*(pt->dist) = t;
		inter = get_inter(ray, t);
		pt->normal = unit_vect(inter.x, inter.y, 0);
		if (scalar_prod(pt->normal, ray.dir) > 0)
			pt->normal = mult_scalar(pt->normal, -1);
		op_inv(cy.trans, cy.rot, &(pt->normal), &inter);
		pt->refl = get_refl(temp, pt->normal);
		pt->color = cy.color;
		pt->inter = inter;
		get_info(pt, light, inter);
	}
}

int				sh_cylinder(void *e, t_ray ray, double dist)
{
	t_cylinder	cy;
	double		t;

	cy = *((t_cylinder *)e);
	change_frame(&ray, cy.inv, mult_scalar(cy.trans, -1));
	t = init_equation(ray, cy);
	if (t < 0 || t > dist - 0.001)
		return (0);
	return (1);
}
