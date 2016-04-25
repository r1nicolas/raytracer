/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:44:10 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/25 16:54:26 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

/*
** Return one rotation matrix to a base with z (0, 0, 1) vector is u in the
** old base. It is used by cone and cylinder, since these objects are
** symetrics around a line all the base with these line as one the axis
** are algoritmicaly identical. u is the direction vector of the object.
*/

double			**matrix_direction(t_vec u)
{
	t_vec		v;
	t_vec		ort;
	double		angle;
	double		**matrix;

	v.x = 0;
	v.y = 0;
	v.z = (double)1;
	ort = vector_cross_product(v, u);
	angle = acos(u.z);
	matrix = create_rotation_matrix(angle, ort);
	return (matrix);
}

/*
** Return the smallest positive solution to the equation ax^2 + bx + c = 0.
** Return a negative number if the are no positive solutions.
*/

double			res_equ_scnd(double a, double b, double c)
{
	double	delta;
	double	x2;
	double	x1;

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
	x1 = (-b - sqrt(delta)) / (2 * a);
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (x1 < 0)
		return (x2);
	if (x2 < 0)
		return (x1);
	return (fmin(x1, x2));
}

/*
** Reverse the base change of the solution of some object that need a base
** change for calculation simplicity (changing base then doing computation
** in the new base then reverting to the original base is easier than doing
** computation in the original base).
*/

void			op_inv(t_vec trans, double **rot, t_vec *normal, t_vec *inter)
{
	*normal = rotation_vector(rot, *normal);
	*inter = rotation_vector(rot, *inter);
	*inter = vector_add(trans, *inter);
}
