/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:44:10 by tlepetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:36:23 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

double			**get_rot_obj(t_vec u)
{
	t_vec		v;
	t_vec		ort;
	double		angle;
	double		**ret;

	init_ret(&ret);
	v.x = 0;
	v.y = 0;
	v.z = (double)1;
	ort = cross_prod(v, u);
	angle = acos(u.z);
	if (angle != 0)
		get_matrice(ret, angle, ort);
	return (ret);
}

double			res_equ_scnd(double a, double b, double c)
{
	double	delta;
	double	t2;
	double	t1;

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				return (0);
			return (-1);
		}
		return (-c / b);
	}
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	return (fmin(t1, t2));
}

void			op_inv(t_vec trans, double **rot, t_vec *normal, t_vec *inter)
{
	apply_rot(rot, normal);
	apply_rot(rot, inter);
	apply_trans(trans, inter);
}
