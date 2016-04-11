/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_unit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:29:53 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/11 17:58:59 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>

t_vec	unit_vect(double a, double b, double c)
{
	t_vec		u;
	double		norm;

	norm = sqrt(a * a + b * b + c * c);
	if (norm)
	{
		u.x = a / norm;
		u.y = b / norm;
		u.z = c / norm;
	}
	else
	{
		u.x = 0;
		u.y = 0;
		u.z = 0;
	}
	return (u);
}

double	dist_point(t_vec u, t_vec v)
{
	apply_trans_inv(u, &v);
	return (norm(v));
}

t_vec	init_point(double x, double y, double z)
{
	t_vec	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

t_vec	mult_scalar(t_vec u, double scalar)
{
	u.x = u.x * scalar;
	u.y = u.y * scalar;
	u.z = u.z * scalar;
	return (u);
}

t_vec	vect_add(t_vec u, t_vec v)
{
	u.x = u.x + v.x;
	u.y = u.y + v.y;
	u.z = u.z + v.z;
	return (u);
}
